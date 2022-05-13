#! /bin/bash

# 算术运算符
a=1
b=2

val=`expr $a + $b`
echo "a + b = $val"

val=`expr $a - $b`
echo "a - b = $val"
# 注意这里乘法必须转义才能实现乘法运算
val=`expr $a \* $b`
echo "a * b = $val"

val=`expr $a / $b`
echo "a / b = $val"

val=`expr $a % $b`
echo "a % b = $val"

val=`expr $a = $b`
echo "a = b : $val"

val=`expr $a != $b`
echo "a !=b : $val"

a=$b
echo "a = $b"
