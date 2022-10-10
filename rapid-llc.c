#include <linux/list.h>
#include <linux/version.h>
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
#include <linux/pid.h>

#define DEFAULT_UE_BW 2050000 // 2MB/s (16 Mbps)
#define INITIAL_WINDOW 10
#define DEFAULT_MSS 1440
#define WS_FACTOR 7
#define MIN_BDP 2000/*2*DEFAULT_MSS*/
#define LTE_EXAMPLE_SR 8000 // we expect 8ms SR periodicity. The best solution is to retreive/estimate SR period. from RNIS 
uint64_t UE_RNIS_RADIO_BW;

const char PEPSAL_PROCESS_NAME[] = "pepsal"; // Pepsal TCP-split proxy user-space program name
#include <linux/cdev.h>
#include <linux/device.h>
#include<linux/slab.h>                 //kmalloc()
#include<linux/uaccess.h>              //copy_to/from_user()
#include <linux/ioctl.h>
 
 
#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)
 
int32_t value = 0;
 
dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;
/*
** Function Prototypes
*/
//static int      __init etx_driver_init(void);
//static void     __exit etx_driver_exit(void);
static int      etx_open(struct inode *inode, struct file *file);
static int      etx_release(struct inode *inode, struct file *file);
static ssize_t  etx_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  etx_write(struct file *filp, const char *buf, size_t len, loff_t * off);
static long     etx_ioctl(struct file *file, unsigned int cmd, unsigned long arg);
/*
** File operation sturcture
*/
static struct file_operations fops =
{
        .owner          = THIS_MODULE,
        .read           = etx_read,
        .write          = etx_write,
        .open           = etx_open,
        .unlocked_ioctl = etx_ioctl,
        .release        = etx_release,
};
/*
** This function will be called when we open the Device file
*/
static int etx_open(struct inode *inode, struct file *file)
{
  //pr_info("Device File Opened...!!!\n");
        return 0;
}
/*
** This function will be called when we close the Device file
*/
static int etx_release(struct inode *inode, struct file *file)
{
  //pr_info("Device File Closed...!!!\n");
        return 0;
}
/*
** This function will be called when we read the Device file
*/
static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
  // pr_info("Read Function\n");
        return 0;
}
/*
** This function will be called when we write the Device file
*/
static ssize_t etx_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
  // pr_info("Write function\n");
        return len;
}
/*
** This function will be called when we write IOCTL on the Device file
*/
static long etx_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
         switch(cmd) {
                case WR_VALUE:
                        if( copy_from_user(&value ,(int32_t*) arg, sizeof(value)) )
                        {
			  //pr_err("Data Write : Err!\n");
                        }
                        //pr_info("Value = %d\n", value);
			UE_RNIS_RADIO_BW = value != 0 ? value : UE_RNIS_RADIO_BW;
                        break;
                case RD_VALUE:
                        if( copy_to_user((int32_t*) arg, &value, sizeof(value)) )
                        {
			  //        pr_err("Data Read : Err!\n");
                        }
                        break;
                default:
                        pr_info("Default\n");
                        break;
        }
        return 0;
}

static int  etx_driver_init(void)
{
        /*Allocating Major number*/
        if((alloc_chrdev_region(&dev, 0, 1, "etx_Dev")) <0){
                pr_err("Cannot allocate major number\n");
                return -1;
        }
        pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));
 
        /*Creating cdev structure*/
        cdev_init(&etx_cdev,&fops);
 
        /*Adding character device to the system*/
        if((cdev_add(&etx_cdev,dev,1)) < 0){
            pr_err("Cannot add the device to the system\n");
            goto r_class;
        }
 
        /*Creating struct class*/
        if((dev_class = class_create(THIS_MODULE,"etx_class")) == NULL){
            pr_err("Cannot create the struct class\n");
            goto r_class;
        }
 
        /*Creating device*/
        if((device_create(dev_class,NULL,dev,NULL,"etx_device")) == NULL){
            pr_err("Cannot create the Device 1\n");
            goto r_device;
        }
        pr_info("Device Driver Insert...Done!!!\n");
        return 0;
 
r_device:
        class_destroy(dev_class);
r_class:
        unregister_chrdev_region(dev,1);
        return -1;
}
/*
**  exit function
*/
static void etx_driver_exit(void)
{
        device_destroy(dev_class,dev);
        class_destroy(dev_class);
        cdev_del(&etx_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver Remove...Done!!!\n");
}

#define NIPQUAD(addr) \
    ((unsigned char *)&addr)[0], \
    ((unsigned char *)&addr)[1], \
    ((unsigned char *)&addr)[2], \
    ((unsigned char *)&addr)[3]

uint64_t mymin(uint64_t a, uint64_t b){
  if (a < b)
    return a;
  return b;
}
uint32_t myminRAN(uint32_t a, uint32_t b){
  if (a < b)
    return a;
  return b;
}

uint64_t mymax(uint64_t a, uint64_t b){
  if (a > b)
    return a;
  return b;
}

/* Check if the socket is owned by the Pepsal user-space program*/
bool is_pepsal(struct sk_buff *sock_buff){
  bool ret = false;
  int cmp_ret = 1;
  if(sock_buff->sk->sk_socket->file != NULL){
    struct task_struct *task = NULL;
    struct file *sock_file = sock_buff->sk->sk_socket->file;
    task = sock_file->f_owner.pid != NULL ? get_pid_task(sock_file->f_owner.pid, PIDTYPE_PID) : task;
    cmp_ret = task != NULL ? strcmp(PEPSAL_PROCESS_NAME,task->comm) : cmp_ret;
    ret = cmp_ret == 0 ? true : false;
  }
  return ret;
}

unsigned int ue_port_from_socket_option(struct sk_buff *sock_buff){
  unsigned int my_sock_mark = 0;
  if (sock_buff->sk->sk_socket != NULL){
    struct socket *mysock = sock_buff->sk->sk_socket;
    struct sock *sk = mysock->sk;
    if (sk != NULL)
      my_sock_mark = sk->sk_mark;
  }
  return my_sock_mark;
}

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
  uint32_t rttran;
  uint32_t rttran_min;
  uint32_t srttran;
  uint32_t srtt_min;
  uint32_t rttmin_sample;
  u64 epoch;
  u64 elapsed;
  u64 ctime;
  unsigned  int mss;
  unsigned  int k_rtt;
  unsigned  int  data;
  bool isSlow;
  uint64_t avail;
  uint64_t ema_prev;
  int mydata;
  
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

uint64_t xtime025(uint64_t x){
  //uint64_t ret = x*13;
  return x >> 3;
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
  flow->mydata+=data;
  int incr;
  
  if((flow->epoch == 0 )&&(flow->srtt > 0)){
    
    flow->rttwan = flow->rttmin <= flow->srtt ? flow->rttmin : flow->srtt;
   
    flow->rttran = flow->rttran_min <= flow->srttran ? flow->rttran_min : flow->srttran;
    
    flow->srtt_min = flow->srttran>0 ? flow->srttran : flow->rttran_min;
    flow->rttmin_sample = flow->srtt_min;
    
    incr = ue->fc == 3 ? 1 : 0;
    uint64_t init_bdp = ((ue->rbw >> (log2ff(ue->fc)+incr))*(flow->rttwan)); // /1000000; // initial BDP in MBytes
    
    init_bdp = init_bdp >> 20;                     // initial BDP in Bytes
    
    flow->bdp = init_bdp;
    flow->rwthresh = init_bdp;
    flow->k_rtt = log2ff(flow->rwthresh >> (log2ff(flow->mss)/*+1*/))+2;//2;
    flow->ctime = (flow->k_rtt)*(flow->rttwan); // categorization period in us
    flow->ctime = flow->ctime << 10;
    flow->epoch =   ktime_get_ns() ;//>> 10; // in us
    flow->elapsed = ktime_get_ns() ;//>> 10; // in us
    flow->arrival_rate = flow->data;
    
  }

  

  if (flow->epoch != 0){
    incr = ue->fc == 3 ? 1 : 0;
    flow->bdp = ((ue->rbw >> (log2ff(ue->fc)+incr))*(flow->rttwan)) >> 20;
    flow->arrival_rate = flow->data;  // in Bytes/s (B/s)
    
    flow->expected_rate = flow->rwthresh; 
    uint64_t rtt_1 = flow->rttwan;
    rtt_1 = rtt_1 << 10;
    u64 period = ktime_get_ns();
    if (((period )-flow->elapsed)>(rtt_1+rtt_1>>1)){ // 1 RTT has passed
      flow->data = 0;
      uint64_t curr_rate = flow->arrival_rate;
     
      flow->ema_prev = flow->ema_prev == 0 ? curr_rate : (curr_rate - xtime04(curr_rate)) + (xtime04(flow->ema_prev));
      flow->rttmin_sample = flow->srttran < flow->rttmin_sample ? flow->srttran : flow->rttmin_sample;
      flow->elapsed = ktime_get_ns() ;/*>> 10;*/ // reset RTT timer
      
    }
    //#if 0
    uint64_t rtt_2 = flow->rttwan;
    period = ktime_get_ns();
    if (((period /*>> 10*/)-flow->epoch)>=flow->ctime+((rtt_2 << 10 >> 1))/*+1100000*//*+2200*/){ // end of categorization period
      flow->arrival_rate+= flow->data;
      flow->ema_prev = flow->ema_prev == 0 ? flow->arrival_rate : (flow->arrival_rate - xtime04(flow->arrival_rate)) + (xtime04(flow->ema_prev));
      uint64_t exp_rate = flow->expected_rate;
      uint64_t avg_rate = flow->ema_prev;
      uint64_t thresh85 = 1*7;
      thresh85 = thresh85 >> 3;
      flow->rttmin_sample = flow->srttran < flow->rttmin_sample ? flow->srttran : flow->rttmin_sample;
      flow->srtt_min = flow->srtt_min == 0 ? flow->rttmin_sample : (flow->srtt_min - xtime025(flow->srtt_min)) + (xtime025(flow->rttmin_sample));
      flow->rttmin_sample = flow->srttran;
      
      if (flow->arrival_rate< ((exp_rate*6) >>3)/*0.75*/){ // flow is slow or app-limited
	 flow->isSlow = true;
      
         flow->rwthresh = mymin(mymax(avg_rate,DEFAULT_MSS),flow->bdp);
	 flow->rwthresh = flow->rwthresh < flow->bdp ? flow->rwthresh : flow->bdp;
         flow->avail = flow->bdp > flow->rwthresh ? flow->bdp - flow->rwthresh: 0; 
	 
      }
      else{
	flow->isSlow = false;
	
	flow->avail = 0;
      }
      
      flow->rttwan = flow->rttmin <= flow->srtt ? flow->rttmin : flow->rttwan;
      flow->rttran = flow->rttran_min <= flow->srttran ? flow->rttran_min : flow->rttran;
      
      flow->bdp = ((ue->rbw >> (log2ff(ue->fc)+incr))*(flow->rttwan)) >> 20;
      update_unused_bw(ue);
      incr = ue->nfast == 3 ? 1 : 0;
      flow->rwthresh = flow->isSlow == true ? flow->rwthresh: mymin((ue->rbw*flow->rttwan)>>20,flow->bdp+(ue->unused >> (log2ff(mymax(ue->nfast,1))+incr)));

      flow->k_rtt = log2ff(flow->rwthresh >> (log2ff(flow->mss)))+1;
      rtt_1 = flow->rttwan;
      rtt_1 = rtt_1 << 10;
      flow->ctime = flow->k_rtt <= 0 ? rtt_1 : (flow->k_rtt)*(rtt_1); // categorization period in ns                                                                                                            
      flow->epoch =   ktime_get_ns()  ;// >> 10; // in ns                                                           
      flow->elapsed = ktime_get_ns(); //>> 10; // in ns 
      flow->ema_prev = 0;
      
    }
      
  }

}

struct rflow *find_ue_by_port(int port, int dport, struct list_head *listhead){
  struct list_head *p,*q;
  struct mobile *ue = NULL;
  struct rflow *found = NULL;
  struct conn *entry = NULL;
  list_for_each(p,listhead)
    {
      ue = list_entry(p,struct mobile,list);
      list_for_each(q,&ue->porttab){
	entry = list_entry(q,struct conn,list);
	if(( entry->port == port)||(entry->port == dport)){
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
    //if((found->mob->fc -1) >= 1){
    list_del(&found->conn_out->list);
    
    /*if((found->mob->fc - 1)>=1)
      list_del(&found->mob->list);
      else*/
    found->mob->fc-=1;//}
  }
}
bool update_ue_info (struct conn *newconn, struct list_head *listhead){
  int i = 0;
  struct list_head *p;
  struct conn *entry = NULL;
  struct conn *found = NULL;
  bool ret = true;
  /*if(listhead = NULL)
    INIT_LIST_HEAD(listhead);*/
  list_for_each(p,listhead)
    {
      entry = list_entry(p,struct conn,list);
      if (entry->port == newconn->port){
	//printk(KERN_INFO "=== [RAPID ] : Port already exists ===\n");
	found = entry;
	ret = false;
        break;
      }
    }
      if (found == NULL){
	list_add(&newconn->list,listhead);
	//printk(KERN_INFO "=== [RAPID ] : new port added ===\n");
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
	//printk(KERN_INFO "=== [RAPID ] : UE in TAB: add new port ===\n");
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
	ueport->rttwan = 0;
	ueport->srtt = 0;
	ueport->rttmin = 0;
	ueport->rttran = 0;
        ueport->srttran = 0;
        ueport->rttran_min = 0;
	ueport->rwthresh = ((INITIAL_WINDOW)*(DEFAULT_MSS));
	ueport->mydata = 0;
	ueport->rttmin_sample = 0;
	ueport->srtt_min = 0;
	if(ue->fc <=0)
	  INIT_LIST_HEAD(&ue->porttab);

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
    firstconn->rttwan = 0;
    firstconn->srtt = 0;
    firstconn->rttmin = 0;
    firstconn->rttran = 0;
    firstconn->srttran = 0;
    firstconn->rttran_min = 0;
    firstconn->mydata = 0;
    firstconn->rttmin_sample = 0;
    firstconn->srtt_min = 0;

    ue_key->fc+=1;
    INIT_LIST_HEAD(&ue_key->porttab);
    list_add(&ue_key->list,listhead);
    //printk(KERN_INFO "=== [RAPID ] : Add new UE!! and new port ===\n");
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
      //printk(KERN_INFO " [RAPIDlog] NO_SKBUFF\n");
        return NF_ACCEPT;
    }

    iph = (struct iphdr *)skb_network_header(sock_buff);

    if (!iph) {
        //printk(KERN_INFO "no ip header\n");
        return NF_ACCEPT;
    }

    /* Target only the TCP sockets owned by Pepsal */

    if((iph->protocol==IPPROTO_TCP) && (is_pepsal(sock_buff))) {
        
        tcp_header = tcp_hdr(sock_buff);
	char source[16];
	snprintf(source, 16, "%pI4", &iph->daddr);
        sport = htons((unsigned short int) tcp_header->source);
	dport = htons((unsigned short int) tcp_header->dest);
        window = htons((unsigned short int) tcp_header->window);

	if ((tcp_header->syn)&&(tcp_header->ack)) { // Spoofed SYN-ACK sent by Pepsal TCP-split proxy to UE
       
	 //printk(KERN_INFO "[RAPID] TCP: source: %d, dest: %d, window: %d \n", sport, dport,window);
	struct mobile *ue = kmalloc(sizeof(struct mobile), GFP_KERNEL);
	snprintf(ue->ip,16,"%pI4",&iph->daddr);
	ue->fc = 0;
	//ue->rbw= DEFAULT_UE_BW;
	ue->rbw = UE_RNIS_RADIO_BW;
	ue->unused = 0;
	add_mobile(ue,mobtab,dport); // This dest port corresponds to the original UE src port
        }
       else if((tcp_header->fin)||(tcp_header->rst)){
	   struct mobile *ue = kmalloc(sizeof(struct mobile), GFP_KERNEL);
           snprintf(ue->ip,16,"%pI4",&iph->daddr);
	   remove_ue_or_conn(dport,mobtab);
	   kfree(ue);
	 }
       else { // Spoofed SYN or data towards server or data towards UE 
	 struct rflow *pep=NULL;
	 unsigned int marked_port = 0; // gives UE src port associated to TCP-WAN socket
	 marked_port = ue_port_from_socket_option(sock_buff);
	 /* Check whether we are on TCP-RAN (i.e., sending to a registered UE src port)*/
	 /* or on TCP-WAN (i.e., sending to the original server)*/
	 /* we know we are on TCP-RAN when dport corresponds to pep->conn_out->port */

	 if (marked_port)
	  pep = find_ue_by_port(marked_port,dport,mobtab); // marked_port should correspond to registered UE src port
	 else
	  pep = find_ue_by_port(dport,marked_port,mobtab); // When sending to UE via TCP-RAN
	   
	 
	 if ((pep != NULL)&&(pep->conn_out != NULL)&&(pep->conn_out->port != dport)){ // i.e. we are sending to the server

	   /** Here, we are modifying TCP-WAN **/

	struct tcp_sock *tp=NULL;
        if(sock_buff->sk!=NULL){
         tp = tcp_sk(sock_buff->sk);
         if(tp!= NULL ){                                                                                                             
	   pep->conn_out->srtt = (tp->srtt_us >> 3);
	   pep->conn_out->rttmin = (minmax_get(&tp->rtt_min));
         }
        }

	 tcp_header->window = ntohs(mymax(pep->conn_out->rwthresh,MIN_BDP) >> WS_FACTOR);
	  tcplen = (sock_buff->len - (iph->ihl << 2));
	  tcp_header->check = 0; 
	  tcp_header->check = tcp_v4_check(tcplen,iph->saddr,iph->daddr,csum_partial((char *)tcp_header, tcplen, 0));
           sock_buff->ip_summed = CHECKSUM_NONE; //stop offloading
	   iph->check = 0;
           iph->check = ip_fast_csum((u8 *)iph, iph->ihl);
	  
	   }
	 if ((pep != NULL)&&(pep->conn_out != NULL)&&(pep->conn_out->epoch != 0)&&(pep->conn_out->port == dport)){

	   /** Here, we are working on TCP-RAN data segments **/
	   
	   struct tcp_sock *tp=NULL;
           if(sock_buff->sk!=NULL){
           tp = tcp_sk(sock_buff->sk);
           if(tp!= NULL ){                                           
           pep->conn_out->srttran = (tp->srtt_us >> 3);
           pep->conn_out->rttran_min = (minmax_get(&tp->rtt_min));
	   pep->conn_out->srtt_min = pep->conn_out->srtt_min == 0 ? pep->conn_out->srttran+1500 : pep->conn_out->srtt_min;
	   uint64_t ranBW = (pep->mob->rbw << 1+log2ff((pep->conn_out->rttran_min + pep->conn_out->rttmin)) )>>20;
	   /**************** Compute CWND for TCP-RAN ****************/
	   ranBW = pep->conn_out->rwthresh << (log2ff(pep->conn_out->rttran_min+(LTE_EXAMPLE_SR<<1))+1);
	   ranBW = ranBW >> (log2ff(pep->conn_out->rttmin));
	   uint32_t ranCWND = ranBW >> log2ff(pep->conn_out->mss);
	   tp->snd_cwnd = mymax(10,ranCWND);           
         }
        }	   
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

    /* Target only the TCP sockets owned by Pepsal */
    if((iph->protocol==IPPROTO_TCP)&& (is_pepsal(sock_buff))) {
                
        tcp_header = tcp_hdr(sock_buff);
        
	if  ((!tcp_header->syn)) { // Here we want to extract  metrics from received TCP-WAN segments
        char source[16];
        snprintf(source, 16, "%pI4", &iph->daddr); 
        sport = htons((unsigned short int) tcp_header->source);
        dport = htons((unsigned short int) tcp_header->dest);
        window = htons((unsigned short int) tcp_header->window);
	struct rflow *pep=NULL;
	unsigned int marked_port = 0; // gives UE src port associated to TCP-WAN socket                                                
	marked_port = ue_port_from_socket_option(sock_buff);
	
	/* Want to know if we are receiving from TCP-WAN */
	/* We are receiving from TCP-WAN when the src port is */
	/* different from the UE original src port */
	
	// search UE based on dport which was created by the proxy as UE src port on TCP-WAN

	if (marked_port)
        pep = find_ue_by_port(marked_port,sport,mobtab); // This port should be already registered by rapid_out
	
	if ((pep != NULL)&&(pep->conn_out != NULL)&&(pep->conn_out->port != sport)){ // Receiving from TCP-WAN

	  /*  We are receiving from the server */
	  /*  because the src port is different */ 
	  /*  from the original UE src port */
	  
        struct tcp_sock *tp=NULL;

	if(sock_buff->data_len > 0){ // Register the amount of received data for flow categorization
	  update_flow_state(pep->mob,pep->conn_out,htons((unsigned short int)iph->tot_len)); 
	  }
      }
          
    }
        return NF_ACCEPT;
  }
   
 return NF_ACCEPT;        

}

static int __init initialize(void) {
    mobtab = kmalloc(sizeof(struct list_head), GFP_KERNEL);
    UE_RNIS_RADIO_BW = DEFAULT_UE_BW;
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
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,13,0)
    nf_register_net_hook(&init_net,&nfin);
    nf_register_net_hook(&init_net,&nfho);
#else
    nf_register_hook(&nfin);
    nf_register_hook(&nfho);
#endif
    etx_driver_init();
    //nf_register_hook(&nfin);
    //nf_register_hook(&nfho);
    return 0;    
}

static void __exit teardown(void) {
    //nf_unregister_hook(&nfho);
    //nf_unregister_hook(&nfin);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,13,0)
    nf_unregister_net_hook(&init_net,&nfho);
    nf_unregister_net_hook(&init_net,&nfin);
#else
    nf_unregister_hook(&nfho);
    nf_unregister_hook(&nfin);
#endif
    kfree(mobtab);
    etx_driver_exit();
}

module_init(initialize);
module_exit(teardown);
MODULE_LICENSE("GPL");
