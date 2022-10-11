ifconfig data 192.168.2.14/24 up
ip netns add server
ip link add veth1 type veth peer name veth2
ip link set veth1 netns server
ip netns exec server ip addr add 11.11.11.2/30 dev veth1
ip netns exec server ip link set veth1 up
brctl addbr br1
ip link set br1 up
ip link set veth2 up
brctl addif br1 veth2
ip addr add 11.11.11.1/30 dev br1
ip netns exec server ip route add default via 11.11.11.1
tc qdisc add dev br1 root netem delay 1ms
ip netns exec server tc qdisc add dev veth1 root netem delay 1ms
