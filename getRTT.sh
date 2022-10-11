IP=$1

if [ $# -lt 1 ]; then
echo "[getRTT] : provide src ip address";
exit 1
fi
echo "time,port,rtt,srtt,rttmin,cwnd,inflight" > rtt.res.csv
while [ 1 ]; do
trace="tmp.rtt"
#trace=$(ss dst $IP -ti | tail -n +2)
ss dst $IP -tni | tail -n +2 > $trace;
ts=$(echo $(($(date +%s%N)/1000000)));
#Nbr=$(echo $trace | wc -l)
Nbr=$(wc -l $trace | awk  '{print $1}');
count=$((Nbr/2 ));
#l=$(echo $trace | grep rtt | wc -l)
#echo $l
if [ $count -gt 0 ]; then
    for flow in $(seq $count); do
	id=$((flow*2));
	l0=$(cat $trace | head -n $id  | tail -n 2 |  grep rtt | wc -l);
	if [ $l0 -gt 0 ]; then
	    ntrace=$(cat $trace | head -n $id  | tail -n 2);
	    port=$(echo $ntrace | grep -o -E $IP":[[:digit:]]*" | awk -F ":" '{print $2}');
	    #ntrace=$( echo $trace | tail -n 1);
	    #srtt=$( echo $trace | awk  '{print $4}' | awk -F ":|/" '{print $2}');
	    srtt=$(echo $ntrace | grep -o -E "rtt:[[:digit:]]*\.[[:digit:]]*/" | awk -F ":|/" '{print $2}');
	    #cwnd=$( echo $trace | awk  '{print $7}' | awk -F ":|/" '{print $2}');
	    cwnd=$(echo $ntrace | grep -o -E "cwnd:[[:digit:]]*" | awk -F ":|/" '{print $2}');
	    #unacked=$( echo $trace | awk  '{print $22}' | awk -F ":|/" '{print $2}');
	    unacked=$(echo $ntrace | grep -o -E "unacked:[[:digit:]]*" | awk -F ":|/" '{print $2}');
	    #rtt=$( echo $trace | awk  '{print $24}' | awk -F ":|/" '{print $2}');
	    rtt=$( echo $ntrace | grep -o -E "rcv_rtt:[[:digit:]]*" | awk -F ":|/" '{print $2}')
	    #rttmin=$( echo $trace | awk  '{print $26}' | awk -F ":|/" '{print $2}');
	    rttmin=$( echo $ntrace | grep -o -E "minrtt:[[:digit:]]*" | awk -F ":|/" '{print $2}')
	    result=$ts","$port","$rtt","$srtt","$rttmin","$cwnd","$unacked;
	    echo $result >> rtt.res.csv
	fi
    done
 #cat rtt.res.csv
fi
#sleep 0.001;
done


