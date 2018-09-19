if (! [ -e text.txt ])
then
    touch text.txt
    echo 1 > text.txt
fi

while ! ln text.txt text.txt.lock
do
    sleep 1
done

for i in {1..100}
do
    n=$(tail -1 text.txt)
    n=$(($n+1))
    echo $n >> text.txt
done
rm -f text.txt.lock
