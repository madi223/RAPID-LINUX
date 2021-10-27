#include <linux/list.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/netdevice.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <net/ip.h>
#include <net/tcp.h>
#include <net/route.h>
#include <net/dst.h>
#include <linux/timekeeping.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <errno.h>
//#include <fcntl.h>
//#include <dirent.h>
//#include <string.h>
//#include <sys/types.h>
#define DEFAULT_UE_BW 32000000 // 32MB/s (256 Mbps)
#define INITIAL_WINDOW 10
#define DEFAULT_MSS 1460
#define WS_FACTOR 7

#define NIPQUAD(addr) \
    ((unsigned char *)&addr)[0], \
    ((unsigned char *)&addr)[1], \
    ((unsigned char *)&addr)[2], \
    ((unsigned char *)&addr)[3]

struct list_head *mobtab;
//uint32_t DEFAULT_UE_BW;
struct conn {
  struct list_head list;
  int port;
  uint64_t bdp;
  uint64_t rwthresh;
  uint64_t arrival_rate;
  uint64_t expected_rate;
  uint32_t srtt;
  uint32_t rttmin;
  uint32_t rttwan;
  uint32_t epoch;
  uint32_t elapsed;
  uint32_t ctime;
  unsigned  int mss;
  unsigned  int k_rtt;
  unsigned  int  data;
  bool isSlow;
  uint64_t avail;
  uint64_t ema_prev;
  
};

struct mobile {
 struct list_head list;
 char ip[16];      // UE's source IP address
 int fc;           // Number of active flows
 uint64_t rbw;    // UE's RAN bandwidth
 uint64_t unused;  // UE's unused bandwidth
 int nfast;        // Number of fast flows
 //struct conn;
 struct list_head porttab;
};

struct rflow {
  struct mobile *mob;
  struct conn *conn_out;
};

int log2ff(unsigned int x) 
{ 
   int log = -1; 
   while(x) { 
    log++; 
    x >>= 1; 
   } 
   return log; 
}
uint64_t xtime04(uint64_t x){
  uint64_t ret = x*13;
  return ret >> 5;
}

void update_unused_bw(struct mobile *ue){
  struct list_head *q;
  struct conn *entry = NULL;
  uint64_t free_bw = 0;
  int fast = ue->fc;
  list_for_each(q,&ue->porttab){
     entry = list_entry(q,struct conn,list);
        if(entry->isSlow){
          free_bw+=entry->avail;
	  fast-=1;
     }
  }
  ue->unused = free_bw;
  ue->nfast = fast;
}

void update_flow_state(struct mobile *ue, struct conn *flow,unsigned int data){
  flow->data+=data;
  //printk(KERN_INFO "[RAPID] #CONN : %d ; rbw : %llu ; rttwan %u \n",ue->fc,ue->rbw,flow->rttwan);
  if(flow->epoch == 0 ){
    flow->rttwan = flow->rttmin; // in us
    uint64_t init_bdp = ((ue->rbw/ue->fc)*(flow->rttwan)); // /1000000; // initial BDP in MBytes
    //printk(KERN_INFO "[RAPID] #init_bdp1 : %llu rttwan: %u\n",init_bdp,flow->rttwan);
    init_bdp = init_bdp >> 20;                     // initial BDP in Bytes
    //printk(KERN_INFO "[RAPID] #init_bdp>>20 : ll%u \n",init_bdp);
    flow->bdp = init_bdp;
    flow->rwthresh = init_bdp;
    flow->k_rtt = log2ff(flow->rwthresh/flow->mss)+1;
    flow->ctime = (flow->k_rtt)*(flow->rttwan); // categorization period in us
    flow->epoch =   ktime_get_ns() >> 10; // in us
    flow->elapsed = ktime_get_ns() >> 10; // in us
    return;
  }

  if (flow->epoch != 0){
    flow->bdp = ((ue->rbw/ue->fc)*(flow->rttwan)) >> 20;
    flow->arrival_rate = ((flow->data)/(flow->rttwan)) >> 20; // in Bytes/s (B/s)
    //flow->arrival_rate = (flow->data)/1000 // in Bytes/s (B/s)
    flow->expected_rate = ((flow->bdp)/(flow->rttwan)) >> 20;
    if (((ktime_get_ns() >> 10)-flow->elapsed)>=flow->rttwan){ // 1 RTT has passed
      flow->data = 0;
      uint64_t curr_rate = flow->arrival_rate;
      //double alpha = 0.4 = 13/32; ((curr_rate)*(1-alpha)) + (flow->ema_prev)*(alpha)
      flow->ema_prev = flow->ema_prev == 0 ? curr_rate : (curr_rate - xtime04(curr_rate)) + (xtime04(flow->ema_prev));
      flow->elapsed = ktime_get_ns() >> 10; // reset RTT timer  
    }
    //#if 0
    if (((ktime_get_ns() >> 10)-flow->epoch)>=flow->ctime){ // end of categorization period
      uint64_t exp_rate = flow->expected_rate;
      uint64_t avg_rate = flow->ema_prev;
      uint64_t thresh85 = 1*7;
      thresh85 = thresh85 >> 3;
      if ((avg_rate/exp_rate)<thresh85/*0.85*/){ // flow is slow or app-limited
	 flow->isSlow = true;
         flow->rwthresh = (avg_rate/exp_rate)*flow->rwthresh;
	 flow->rwthresh = flow->rwthresh < flow->bdp ? flow->rwthresh : flow->bdp;
         flow->avail = flow->bdp > flow->rwthresh ? flow->bdp - flow->rwthresh: 0; //std::abs( m_rw - m_bdp);
	 //ue->unused+=flow->avail;
      }
      else{
	flow->isSlow = false;
	//ue->unused-=flow->avail;
	flow->avail = 0;
      }
      // rediscover RTTmin : I'll keep it for now (might solve the issue with UDP flows)
      //flow->rttwan = flow->rttmin; // in us
      flow->bdp = ((ue->rbw/ue->fc)*(flow->rttwan))/1000000;
      update_unused_bw(ue);
      flow->rwthresh = flow->isSlow == true ? flow->rwthresh: flow->bdp + (ue->unused/ue->nfast);
      flow->k_rtt = log2ff(flow->rwthresh/flow->mss)+1;
      flow->ctime = (flow->k_rtt)*(flow->rttwan); // categorization period in us                                                                                                            
      flow->epoch =   ktime_get_ns() >> 10; // in us                                                           
      flow->elapsed = ktime_get_ns() >> 10; // in us 
      flow->ema_prev = 0;
    }
    //#endif  
  }

}

struct rflow *find_ue_by_port(int port, struct list_head *listhead){
  struct list_head *p,*q;
  struct mobile *ue = NULL;
  struct rflow *found = NULL;
  struct conn *entry = NULL;
  list_for_each(p,listhead)
    {
      ue = list_entry(p,struct mobile,list);
      list_for_each(q,&ue->porttab){
	entry = list_entry(q,struct conn,list);
	if(ipcalc(ue->ip,entry->port)==port){
	  found = kmalloc(sizeof(struct rflow), GFP_KERNEL);
	  found->mob = ue;
	  found->conn_out = entry;
	  break;
	}
      }
   }
  return found;
}

struct rflow *find_ue_entry(int port, struct list_head *listhead){
  struct list_head *p,*q;
  struct mobile *ue = NULL;
  struct rflow *found = NULL;
  struct conn *entry = NULL;
  list_for_each(p,listhead)
    {
      ue = list_entry(p,struct mobile,list);
      list_for_each(q,&ue->porttab){
        entry = list_entry(q,struct conn,list);
        if(entry->port==port){
          found = kmalloc(sizeof(struct rflow), GFP_KERNEL);
          found->mob = ue;
          found->conn_out = entry;
          break;
        }
      }
   }
  return found;
}


void remove_ue_or_conn(int port, struct list_head *listhead){
  struct rflow *found = NULL;
  found = find_ue_entry(port,listhead);
  if(found != NULL){
    list_del(&found->conn_out->list);
    if((found->mob->fc - 1)<=0)
      list_del(&found->mob->list);
    else
      found->mob->fc-=1;
  }
}
bool update_ue_info (struct conn *newconn, struct list_head *listhead){
  int i = 0;
  struct list_head *p;
  struct conn *entry = NULL;
  struct conn *found = NULL;
  bool ret = true;
  list_for_each(p,listhead)
    {
      entry = list_entry(p,struct conn,list);
      if (entry->port == newconn->port){
	printk(KERN_INFO "=== [RAPID ] : Port already exists ===\n");
	found = entry;
	ret = false;
        break;
      }
    }
      if (found == NULL){
	list_add(&newconn->list,listhead);
	printk(KERN_INFO "=== [RAPID ] : new port added ===\n");
      }
      return ret;
}
  void add_mobile(struct mobile *ue_key, struct list_head *listhead,int port){
  int i =0;
  struct list_head *p;
  struct mobile *ue = NULL;
  struct mobile *found_ue = NULL;
  list_for_each(p,listhead)
    {
      ue = list_entry(p,struct mobile,list);
      if (strcmp(ue->ip,ue_key->ip)==0){
	printk(KERN_INFO "=== [RAPID ] : UE in TAB: add new port ===\n");
	struct conn *ueport = kmalloc(sizeof(struct conn), GFP_KERNEL);
	ueport->port = port;
	ueport->bdp = ((INITIAL_WINDOW)*(DEFAULT_MSS));
        ueport->data = 0;
        ueport->mss = 1460;
        ueport->isSlow = false;
	ueport->epoch = 0;
	ueport->elapsed = 0;
	ueport->ctime = 0;
	ueport->avail = 0;
	ueport->ema_prev = 0;
	ueport->rwthresh = ((INITIAL_WINDOW)*(DEFAULT_MSS));

	if(update_ue_info(ueport,&ue->porttab))
	  ue->fc+=1;
	found_ue = ue;
	break;
      }
    }

  if (found_ue == NULL ){
    struct conn *firstconn = kmalloc(sizeof(struct conn), GFP_KERNEL);
    firstconn->port = port;
    firstconn->bdp = ((INITIAL_WINDOW)*(DEFAULT_MSS));
    firstconn->data = 0;
    firstconn->mss = 1460;
    firstconn->isSlow = false;
    firstconn->epoch = 0;
    firstconn->elapsed = 0;
    firstconn->ctime =	0;
    firstconn->avail = 0;
    firstconn->ema_prev = 0;
    firstconn->rwthresh = ((INITIAL_WINDOW)*(DEFAULT_MSS));

    ue_key->fc+=1;
    INIT_LIST_HEAD(&ue_key->porttab);
    list_add(&ue_key->list,listhead);
    printk(KERN_INFO "=== [RAPID ] : Add new UE!! and new port ===\n");
    update_ue_info(firstconn,&ue_key->porttab);
  }

}
//static struct mobile mobile_list;

int ipcalc(char *ip, int port)
{
        char *str ; //= kmalloc(sizeof(ip), GFP_KERNEL); //(char *) malloc(sizeof(ip));
	str=kstrdup(ip,GFP_KERNEL);
        //strcpy(str, ip);
        //str = ip;
        int init_size = strlen(str);
        char delim[] = ".";
	// printk("%s\n", str);
        char *ptr = strsep(&str, delim);
        int val = 0;
        while (ptr != NULL)
        {
	  //printk("%s\n", ptr);
                val+=simple_strtol(ptr,NULL,10);
                ptr = strsep(&str, delim);
        
        }
        kfree(str);
        
        return val+port;
}


static struct nf_hook_ops nfho,nfin;
struct iphdr *iph;
struct tcphdr *tcp_header;
struct sk_buff *sock_buff;
unsigned int sport, dport,window,tcplen;
static uint8_t flags;
unsigned int rapid_func_out(unsigned int hooknum,
                       struct sk_buff **skb,
                       const struct net_device *in,
                       const struct net_device *out,
                       int (*okfn)(struct sk_buff *)) 
{
    
    sock_buff = skb;

    if (!sock_buff) {
        return NF_ACCEPT;
    }

    iph = (struct iphdr *)skb_network_header(sock_buff);

    if (!iph) {
        //printk(KERN_INFO "no ip header\n");
        return NF_ACCEPT;
    }

    if(iph->protocol==IPPROTO_TCP) {
        
        tcp_header = tcp_hdr(sock_buff);
	char source[16];
	snprintf(source, 16, "%pI4", &iph->daddr);
        sport = htons((unsigned short int) tcp_header->source);
	dport = htons((unsigned short int) tcp_header->dest);
        window = htons((unsigned short int) tcp_header->window);
        
       if ((tcp_header->syn)&&(tcp_header->ack)) {
       
	 //printk(KERN_INFO "[RAPID] TCP: source: %d, dest: %d, window: %d \n", sport, dport,window);
	struct mobile *ue = kmalloc(sizeof(struct mobile), GFP_KERNEL);
	snprintf(ue->ip,16,"%pI4",&iph->daddr);
	ue->fc = 0;
	ue->rbw= DEFAULT_UE_BW;
	ue->unused = 0;
	add_mobile(ue,mobtab,dport);
        }
       else if((tcp_header->fin)||(tcp_header->rst)){
	   struct mobile *ue = kmalloc(sizeof(struct mobile), GFP_KERNEL);
           snprintf(ue->ip,16,"%pI4",&iph->daddr);
	   remove_ue_or_conn(dport,mobtab);
	   kfree(ue);
	 }
       else {
	 struct rflow *pep=NULL;
	 pep = find_ue_by_port(sport,mobtab);
	 if ((pep != NULL)&&(pep->conn_out != NULL)){

	struct tcp_sock *tp=NULL;
        if(sock_buff->sk!=NULL){
         tp = tcp_sk(sock_buff->sk);
         if(tp!= NULL ){                                                                                                                           
           //printk(KERN_INFO "[RAPID] SRTT :%u ; RTT_min : %u",tp->srtt_us >> 3,minmax_get(&tp->rtt_min));
	   pep->conn_out->srtt = (tp->srtt_us >> 3)/*/1000*/;
	   pep->conn_out->rttmin = (minmax_get(&tp->rtt_min))/*/1000*/;
         }
        }

	tcp_header->window = ntohs(pep->conn_out->rwthresh >> WS_FACTOR);
	   //unsigned int tcplen;
	   //tcplen = sock_buff->len - ip_hdrlen(sock_buff) - 14;
	   //tcp_header->check = 0;
	   //tcp_header->check = tcp_v4_check(tcplen, iph->saddr, iph->daddr, csum_partial((char *)tcp_header, tcplen, 0));
	  tcplen = (sock_buff->len - (iph->ihl << 2));
	  tcp_header->check = 0; 
	  tcp_header->check = tcp_v4_check(tcplen,iph->saddr,iph->daddr,csum_partial((char *)tcp_header, tcplen, 0));
	   //tcp_header->check = ~tcp_v4_check(sizeof(struct tcphdr), iph->saddr,iph->daddr, 0);
           sock_buff->ip_summed = CHECKSUM_NONE; //stop offloading
	   iph->check = 0;
	   //ip_send_check(iph); //ip checksum
           iph->check = ip_fast_csum((u8 *)iph, iph->ihl);
	   //#endif
	   //printk(KERN_INFO "[RAPID] OLD window: %d, NEW window: %d \n", window,htons((unsigned short int) tcp_header->window));
	   //printk(KERN_INFO "[RAPID] OLD window: %d, NEW : %d ; RWthresh: %llu ; isSLOW : %d\n", window,htons((unsigned short int) tcp_header->window),pep->conn_out->rwthresh,pep->conn_out->isSlow /*>>7*/);
	   }
	}
        return NF_ACCEPT;
    }

 return NF_ACCEPT;        

}


unsigned int rapid_func_in(unsigned int hooknum,
                       struct sk_buff **skb,
                       const struct net_device *in,
                       const struct net_device *out,
                       int (*okfn)(struct sk_buff *)) 
{
    
    sock_buff = skb;

    if (!sock_buff) {
        return NF_ACCEPT;
    }

    iph = (struct iphdr *)skb_network_header(sock_buff);

    if (!iph) {
        //printk(KERN_INFO "no ip header\n");
        return NF_ACCEPT;
    }

    if(iph->protocol==IPPROTO_TCP) {
        
        
        tcp_header = tcp_hdr(sock_buff);
        
       if  ((!tcp_header->syn)) {
        char source[16];
        snprintf(source, 16, "%pI4", &iph->daddr);
        //ipcalc(source,dport); 
        sport = htons((unsigned short int) tcp_header->source);
        dport = htons((unsigned short int) tcp_header->dest);
        window = htons((unsigned short int) tcp_header->window);
	// printk(KERN_INFO "[RAPID] TCP: source: %d, dest: %d, window: %d \n", sport, dport,window);
        //printk(KERN_INFO "SKBuffer: len %d, data_len %d\n", sock_buff->len, sock_buff->data_len);
        //ipcalc(source,dport);
	//struct mobile ue;
	//struct mobile *ue = kmalloc(sizeof(struct mobile), GFP_KERNEL);
	//snprintf(ue->ip,16,"%pI4",&iph->daddr);
	struct rflow *pep=NULL;
        pep = find_ue_by_port(dport,mobtab);
         if ((pep != NULL)&&(pep->conn_out != NULL)){
        struct tcp_sock *tp=NULL;
        if(sock_buff->sk!=NULL){
         tp = tcp_sk(sock_buff->sk);
         if(tp!= NULL ){
	   //unsigned int payload = sock_buff->len - sizeof(struct tcphdr) - sizeof(struct iphdr);
	   //pep->conn_out->data+=sock_buff->data_len;
           //printk(KERN_INFO "[RAPID] Data: %d; D+: %d;  SRTT :%u ; RTT_min : %u",/*payload*/sock_buff->data_len,pep->conn_out->data,tp->srtt_us >> 3,minmax_get(&tp->rtt_min));
	   pep->conn_out->srtt = (tp->srtt_us >> 3)/*/1000*/;
           pep->conn_out->rttmin =(minmax_get(&tp->rtt_min))/*/1000*/;
         }
        }
	if(sock_buff->data_len > 0){
	  //pep->conn_out->data+=sock_buff->data_len;
	  update_flow_state(pep->mob,pep->conn_out,sock_buff->data_len);
	}
      }
	//add_mobile(ue,mobtab,dport);
	
        }
        return NF_ACCEPT;
    }
   
 return NF_ACCEPT;        

}

static int __init initialize(void) {
    mobtab = kmalloc(sizeof(struct list_head), GFP_KERNEL);
    INIT_LIST_HEAD(mobtab);
    nfho.hook = rapid_func_out;
    nfin.hook = rapid_func_in;
    //nfho.hooknum = NF_INET_PRE_ROUTING;
    //Interesting note: A pre-routing hook may not work here if our Vagrant
    //                  box does not know how to route to the modified source.
    //                  For the record, mine did not.
    nfho.hooknum = NF_INET_LOCAL_OUT; //NF_INET_POST_ROUTING;
    nfin.hooknum = NF_INET_LOCAL_IN;
    nfho.pf = PF_INET;
    nfin.pf = PF_INET;
    nfin.priority = NF_IP_PRI_FIRST;
    nfho.priority = NF_IP_PRI_FIRST;
    nf_register_hook(&nfin);
    nf_register_hook(&nfho);
    return 0;    
}

static void __exit teardown(void) {
    nf_unregister_hook(&nfho);
    nf_unregister_hook(&nfin);

    kfree(mobtab);
}

module_init(initialize);
module_exit(teardown);
MODULE_LICENSE("GPL");
