#! /bin/bash

fun_return()
{
    a=234
    echo $a
}

fun_return
echo "函数返回值 == $?"