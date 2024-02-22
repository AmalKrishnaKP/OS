#!/bin/bash

choice="y"

while [ $choice == "y" ];
do
        echo "enter first number"
        read num1
        echo "enter number two"
        read num2


        echo "1.Addition"
        echo "2.Subtraction"
        echo "3.Multiplication"
        echo "4.Division"
        echo "5.Modulus"

        echo "enter the choice"
        read num


        case $num in

                1)
                        result=$(($num1+$num2))
                        echo "sum is $result"
                        ;;
                2)
                        result=$(($num1-$num2))
                        echo "result is $result"
                        ;;
                3)
                        result=$(($num1*$num2))
                        echo "product is $result"
                        ;;
                4)
                        result=$(($num1/$num2))
                        echo "result is $result"
                        ;;
                5)
                        result=$(($num1%$num2))
                        echo "reminder is $result"
                        ;;
                *)
                        echo "invalied"
                        ;;
        esac
        echo "do you want to rpt"
        read choice
done
                    
