#! /bin/bash

a=1
b=2
c=1

if [ $a == $b ]
then
    echo "a = b"
elif [ $a = $c ]
then
    echo "a == 1"
else
    echo "a != b"
fi

val=`expr $a != $b`
if [ val ] 
then
    echo "a != b"
else 
    echo "a == b"
fi
