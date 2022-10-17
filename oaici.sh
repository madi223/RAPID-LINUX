#!/bin/bash

####################
# These are functions used to handle OAICI functions from faraday
#
#


# init-epc expects the following argument
# * the fit ID (01-37) where to run the EPC, e.g., 17
# * the fit ID (01-37) where to run the eNB, e.g., 23
function init-epc (){
    epc=$1; shift
    enb=$1; shift
    
    ssh root@fit$epc \
	    "echo 'Do some network manipulations for containers to talk to each other';
    	    sysctl net.ipv4.conf.all.forwarding=1;
    	    iptables -P FORWARD ACCEPT;
            ip route add 22.22.22.0/24 via 192.168.3.26;
    	    ip route add 192.168.61.0/26 via 192.168.3.$enb dev control;
            tc qdisc add dev control root netem delay 4ms;"
}

# start-epc expects the following argument
# * the fit ID (01-37) where to run the EPC, e.g., 17
function start-epc (){
    epc=$1; shift
    
    sshpass -p "linux" ssh oaici@fit$epc \
	    "echo 'Deploy the EPC';
    	    cd openair-epc-fed/docker-compose/inria-oai-mme/;
    	    echo 'docker-compose config --service'; docker-compose config --service;
    	    echo 'docker-compose up -d db_init'; docker-compose up -d db_init;
    	    echo 'wait for 50s'; sleep 50;
	    docker logs prod-db-init;
    	    echo 'docker-compose up -d oai_spgwu trf_gen'; docker-compose up -d oai_spgwu trf_gen;
    	    echo 'Wait for 30s'; sleep 30;
	    docker logs prod-oai-mme;"
    
}

# stop-epc expects the following argument
# * the fit ID (01-37) where runs the EPC, e.g., 17
function stop-epc (){
    epc=$1; shift
    
    sshpass -p "linux" ssh oaici@fit$epc \
	    "echo 'Stop the EPC';
    	    cd openair-epc-fed/docker-compose/inria-oai-mme/;
    	    echo 'docker-compose down'; docker-compose down"
}


# init-enb expects the following argument
# * the fit ID (01-37) where to run the eNB, e.g., 23
# * the fit ID (01-37) where to run the EPC, e.g., 17
function init-enb (){
    enb=$1; shift
    epc=$1; shift
    
    ssh root@fit$enb \
	    "echo 'Do some network manipulations for containers to talk to each other'; 
	    sysctl net.ipv4.conf.all.forwarding=1; 
    	    iptables -P FORWARD ACCEPT; 
            ifconfig data 192.168.2.23/24 up;
    	    ip route add 192.168.61.192/26 via 192.168.3.$epc dev control;"
}

function init-rapid (){
    rapid=$1; shift
    #scp getRANstat.py root@fit$rapid":";
    ssh root@fit$rapid \
            "echo 'Configure RAPID IP addresses, start rabbit-mq and FlexRAN';                                                                                                       
            sysctl net.ipv4.conf.all.forwarding=1;                                                                                                                                           
            iptables -P FORWARD ACCEPT;                                                                                                                                                      
            ifconfig data 192.168.2.26/24 up;
            ifconfig data:serv 22.22.22.1/24 up;
            tc qdisc add dev data root netem delay 10ms;
            tc qdisc add dev control root netem delay 4ms;
            docker start rabbitmq;
            sysctl -w net.ipv4.tcp_congestion_control=reno;
            ip route change 192.168.3.0/24 dev control proto static initrwnd 80;"
            
}

function start-rapid (){
    rapid=$1; shift
    ssh root@fit$rapid \
	  "echo 'launching pepsal and RAPID kernel module';
           rm -rf *;
           git clone https://github.com/madi223/RAPID-LINUX.git;
           cd ~/RAPID-LINUX/flexran-rtc;
           nohup sh run_flexran_rtc.sh > flex.out 2> flex.err < /dev/null &
           cd ~/RAPID-LINUX/pepsal/;
           make;
           make install;
           cd ~/RAPID-LINUX/;
           sh pepconf.sh;
           nohup python3 pub_stat.py > rnis.out 2> rnis.err < /dev/null &
           pepsal -d -l /root/pep.log -v;
           make;
           insmod rapid-llc.ko;"
    }

function init-router (){
    rapid=$1; shift
    rapid="0"$rapid;

    ssh root@fit$rapid \
	"echo 'Configure Middle Backhaul router and limit BW to 1Gbps';
        sysctl net.ipv4.conf.all.forwarding=1;
        ifconfig data 192.168.2.2/24 up;
        ifconfig data:serv 22.22.22.4/24 up; 
        tc qdisc add dev data root netem delay 10ms; 
        ip route add 192.168.3.17/32 via 22.22.22.1;                                                                                    
        ip route add 192.168.3.26/32 via 22.22.22.1;
        apt install iperf3 -y"
    }
#cd flexran-rtc;
#nohup sh run_flexran_rtc.sh > flex.out 2> flex.err < /dev/null &
function init-cubic (){
    rapid=$1; shift
    rapid="0"$rapid;
    scp http-ev getRTT.sh root@fit$rapid":";
    ssh root@fit$rapid -C "nohup /root/http-ev  > ht8080.out 2> ht8080.err < /dev/null &";
    ssh root@fit$rapid -C "nohup /root/http-ev -l 80  > ht80.out 2> ht80.err < /dev/null &";
    ssh root@fit$rapid \
            "echo 'Configure CUBIC CCA on fit07 and add Virtual IP';                                                                                                                         
            sysctl net.ipv4.conf.all.forwarding=1;                                                                                                                                           
            iptables -P FORWARD ACCEPT;                                                                                                                                                      
            ifconfig data 192.168.2.7/24 up;                                                                                                                                                 
            ifconfig data:serv 22.22.22.2/24 up;
            tc qdisc add dev data root netem delay 10ms;       
            ip route add 192.168.3.17/32 via 22.22.22.1;
            ip route add 192.168.3.26/32 via 22.22.22.1;
            sysctl net.ipv4.tcp_congestion_control=cubic;"
}
function init-bbr (){
    rapid=$1; shift
    scp	http-ev	getRTT.sh root@fit$rapid":"
    ssh root@fit$rapid -C "nohup /root/http-ev  > ht8080.out 2> ht8080.err < /dev/null &";
    ssh root@fit$rapid -C "nohup /root/http-ev -l 80  > ht80.out 2> ht80.err < /dev/null &";
    ssh root@fit$rapid \
            "echo 'Configure BBR CCA on fit19 and add Virtual IP';                                               
            sysctl net.ipv4.conf.all.forwarding=1;
            iptables -P FORWARD ACCEPT;
            ifconfig data 192.168.2.19/24 up;
            ifconfig data:serv 22.22.22.3/24 up;
            tc qdisc add dev data root netem delay 10ms;
            ip route add 192.168.3.17/32 via 22.22.22.1;
            ip route add 192.168.3.26/32 via 22.22.22.1;
            sysctl net.ipv4.tcp_congestion_control=bbr;"
}


# start-enb expects the following argument
# * the fit ID (01-37) where to run the eNB, e.g., 23
function start-enb (){
    enb=$1; shift
    
    sshpass -p "linux" ssh oaici@fit$enb \
	    "echo 'Deploy the eNB';
    	    cd ~/openairinterface5g/ci-scripts/yaml_files/inria_enb_mono_fdd;
            echo 'enable flexran'; sed -i '27s/no/yes/g' docker-compose.yml;
            echo 'change flexran IP address'; sed -i 's/FLEXRAN_IPV4_ADDRESS: [0-9]*\.[0-9]*\.[0-9]*\.[0-9]*/FLEXRAN_IPV4_ADDRESS: 192\.168\.3\.26/g' docker-compose.yml;
	    echo 'docker-compose config --service'; docker-compose config --service;
    	    echo 'docker-compose up -d enb_mono_fdd'; docker-compose up -d enb_mono_fdd;"
}

# stop-enb expects the following argument
# * the fit ID (01-37) where to run the eNB, e.g., 23
function stop-enb (){
    enb=$1; shift
    
    sshpass -p "linux" ssh oaici@fit$enb \
	    "echo 'Stop the eNB';
    	    cd ~/openairinterface5g/ci-scripts/yaml_files/inria_enb_mono_fdd;
	    echo "docker-compose down"; docker-compose down"
}

# logs-mme expects the following argument
# * the fit ID (01-37) where EPC runs, e.g., 17
function logs-mme (){
    epc=$1; shift

    sshpass -p "linux" ssh oaici@fit$epc \
	    "cd openair-epc-fed/docker-compose/inria-oai-mme/;
    	    echo 'docker logs prod-oai-mme --follow'; docker logs prod-oai-mme --follow"
}

# logs-enb expects the following argument
# * the fit ID (01-37) where runs the eNB, e.g., 23
function logs-enb (){
    enb=$1; shift

    sshpass -p "linux" ssh oaici@fit$enb \
            "cd ~/openairinterface5g/ci-scripts/yaml_files/inria_enb_mono_fdd;
            echo 'docker logs prod-enb-mono-fdd --follow';
            docker logs prod-enb-mono-fdd --follow"
}

########################################
# just a wrapper so we can call the individual functions from faraday. so e.g.
# oaici.sh logs-enb 23
#

"$@"

