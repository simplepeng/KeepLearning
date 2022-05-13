#! /bin/bash

function fun1
{
    echo "这是函数----fun1"
}

function fun2()
{
    echo "这是函数----fun2"
}

fun3()
{
    echo "这是函数----fun3"
}

echo "执行函数-开始"
fun1
fun2
fun3
echo "执行函数-结束"