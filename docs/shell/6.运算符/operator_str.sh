#!/bin/bash

str1="abc"
str2="efg"

if [ $str1 = $str2 ]
then 
    echo "str1 == str2"
else
    echo "str1 != str2"
fi

if [ -z $str1 ]
then
    echo "str 字符串长度为0"
else 
    echo "str 字符串长度不为0"
fi

