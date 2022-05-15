#! /bin/bash

fun_arg()
{
    echo "第0个参数 ==  $0 "
    echo "第1个参数 ==  $1 "
    echo "第2个参数 ==  $2 "
    echo "所有参数 ==  $* "
}

fun_arg 1 2 3 4 5 
