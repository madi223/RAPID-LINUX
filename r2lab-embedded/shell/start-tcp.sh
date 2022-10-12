NUM=$1
n=1
rm -rf tcp-res.txt 2> /dev/null
touch tcp-res.txt
while [ $n -le $NUM ]
do
    echo "************************************************************" >> tcp-res.txt
    { time scp root@172.16.0.1:/root/tcp/1MB /dev/null ; } 2>> tcp-res.txt
    echo "**********************************************************" >> tcp-res.txt
    sleep 20
    n=$(( n+1 )) # increments $n
done
