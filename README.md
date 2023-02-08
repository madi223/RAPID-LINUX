# RAPID-LINUX
RAPID implementation in Linux: Using pepsal for TCP-split and a new kernel module (rapid.ko) that implements RAPID's algorithms
<img src="r2lab-testbed.png" alt="OAI r2lab testbed"/>
<br/>
# 0. Initial step : Build the testbed on R2LAB
Clone this repository and launch the deployment script. This may take several minutes.

```
git clone https://github.com/madi223/RAPID-LINUX.git
cd RAPID-LINUX
python3 deploy-rapid.py -s inria_quic -P0 -Q32
```
# 1. Subscribing to FlexRAN RNIS and Launching Pepsal

## 1.1 Subscribe to FlexRAN RNIS

From the faraday gateway, connect to the RAPID node (fit26) via the commands below: 

```
ssh root@fit26
python3 pub_stat.py

```
## 1.2 Launch Pepsal
Open another terminal on the faraday gateway and run the commands below:

```
ssh root@fit26
pepsal -d -v /root/peplog.log
```
# 2. Launching normal/unintercepted HTTP traffic from Quectel UE

## 2.1. Record CWND and RTT traces
Connect to the end servers (fit07 and fit19). Then launch the script that records CWND and RTT traces on both of them:

```
ssh root@fit07
./getRTT.sh 192.168.3.17
```

On another terminal :

``` 
ssh root@fit19
./getRTT.sh 192.168.3.17 

```

## 2.2 Launch wget from the UE
Connect to the Quectel UE (fit32). Set up routes to reach the servers via radio interface, and download data from the Cubic and BBR servers at the same time using wget. In this scenario, you have to use an HTTP port that is not intercepted by RAPID (i.e., 80 by default). 

```
ssh root@fit32
ip route add 22.22.22.0/24 dev wwan0
wget http://22.22.22.2:80/60M --report-speed=bits --delete-after -O /dev/null -o cubic.001.log & wget http://22.22.22.3:80/60M --report-speed=bits --delete-after -O /dev/null -o bbr.001.log

```
Once the download is complete, go back to fit07 and fit19 and stop the recording (i.e., Ctrl+c).Thenyou will find a log file named **rtt.res.csv**. This file contains relevant information about each connection and contains the following field: port,rtt,srtt,rttmin,cwnd,unacked_bytes.

# 3. Launching RAPID intercepted HTTP traffic from Quectel UE

## 3.1. Build and load the RAPID kernel module
Connect to the RAPID node (fit26), then launch the following commands:

```
ssh root@fit26
cd RAPID-LINUX
make
insmod rapid-llc.ko
```
## 3.2. Advertise FlexRAN info on the local Rabbit-mq broker
On the previous terminal (fit26), launch the following python commands:

```
cd /root/
python3 pub_stat.py
```
## 3.3. Configure and launch pepsal TCP-split proxy
Open a new terminal on the RAPID node (fit26), then launch the following commands:

```
ssh root@fit26
./pepconf.sh
pepsal -d -v -l /root/pep.log
```

## 3.4. Record CWND and RTT traces
Connect to the RAPID node (fit26) on another terminal, then launch the script that records CWND and RTT traces:

```
ssh root@fit26
./getRTT.sh 192.168.3.17
```

## 3.5 Launch wget from the UE
Connect to the Quectel UE (fit32). Set up routes to reach the servers via radio interface, and download data from the Cubic and BBR servers at the same time using wget. In this scenario, you have to use the intercepted HTTP port (i.e., 8080 , as indicated in pepconf.sh). 

```
ssh root@fit32
ip route add 22.22.22.0/24 dev wwan0
wget http://22.22.22.2:8080/60M --report-speed=bits --delete-after -O /dev/null -o cubic.rapid.001.log & wget http://22.22.22.3:8080/60M --report-speed=bits --delete-after -O /dev/null -o bbr.rapid.001.log

```
Once the download is complete, go back to fit26 and stop the recording (i.e., Ctrl+c).Thenyou will find a log file named **rtt.res.csv**. This file contains relevant information about each intercepted connection (port,rtt,srtt,rttmin,cwnd,unacked_bytes).

