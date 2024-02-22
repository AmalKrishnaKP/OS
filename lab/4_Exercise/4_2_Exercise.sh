#!/bin/bash
file="a.txt"
echo "enter the word to search"
read item
count=0
while read -r new;
do
        for word in $new;
        do
                if [ $item == $word ];
                then
                        count=$(($count + 1))
                fi
        done
done<$file
if [ $count -eq 0 ]
then
        echo "the word is absend"
else
        echo "the word present in $count times"
fi
