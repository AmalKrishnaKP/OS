#!/bin/bash

File=$(df -h)
disk=$(lsblk)
mry1=$(free -h)
cpu=$(lscpu)
shell=$(cat /etc/shells)
os1=$(lsb_release -a)
os2=$(cat /etc/debian_version)
os3=$(uname -r)
choice="y"
while [ $choice == "y" -o choice == "Y" ];
do
        echo "1.OS Details"
        echo "2.Shells"
        echo "3.CPU Details"
        echo "4.Memmory Information"
        echo "5.HardDisk INFO"
        echo "6.FileSystem"
        echo "enter the number"
        read num
        case $num in
                1)
                        echo $os1
                        echo $os2
                        echo $os3
                        ;;
                2)
                        echo $shell
                        ;;
                3)
                        echo $cpu
                        ;;
                4)
                        echo $mry1
                        ;;
                5)
                        echo $disk
                        ;;
                6)
                        echo $File
                        ;;
                *)
                        echo "invalied"
                        ;;
        esac
        echo "do u want to rpt(y/n)"
        read choice
done                        
