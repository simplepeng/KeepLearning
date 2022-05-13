#!/bin/bash

arr=(1 2 3 'a' "b")
# 获取数组中的元素
echo ${arr[0]}
echo ${arr[3]}
# 获取数组所有元素
echo ${arr[@]}
echo ${arr[*]}
# 获取数组值的个数
echo ${#arr[@]}
echo ${#arr[*]}