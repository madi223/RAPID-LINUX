iptables -A PREROUTING -t mangle -p tcp --dport 8080 -i control -j TPROXY --on-port 5000 --tproxy-mark 1
ip rule add fwmark 1 lookup 100
ip route add local 0.0.0.0/0 dev lo table 100
