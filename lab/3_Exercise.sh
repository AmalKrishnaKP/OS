#!/bin/bash

echo "enter the number of terms"
read num
echo ""
echo ""
echo "numbers are:"
echo ""
echo ""
if [ $num -eq 1 ]
then
        echo "0"
elif [ $num -eq 2 ]
then
        echo "0"
        echo "1"
else
        a=0
        b=1
        echo "0"
        echo "1"
        rep=3
        while [ $rep -le $num ]
        do
                expr $(($a + $b))
                res=$(($a + $b))
                a=$b
                b=$res
                rep=$(($rep + 1))
                sleep 0.5
        done
fi
