# 流程控制

与其他语言不同，Shell的流程控制块不能为空。

比如其他语言可以在`else`代码块中不写逻辑，但是`sh/bash`里不能这么写。

## 逻辑控制-if

```shell
if 表达式
then
	...
elif 表达式
then
	...
else
	...
fi
```

```shell
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
```

> a == 1
> a != b

## 循环-for

```shell
for 变量 in 集合
do
	...
done
```

```shell
#! /bin/bash

for i in 1 2 3 4
do
    echo "value == ${i}"
done
```

> value == 1
> value == 2
> value == 3
> value == 4

## 循环-while

```shell
while 表达式
do
	...
done
```

## 无线循环

```shell
while :
do
    command
done
```

或者

```shell
while true
do
    command
done
```

## 循环-until

until 循环执行一系列命令直至条件为 true 时停止。

until 循环与 while 循环在处理方式上刚好相反。

一般 while 循环优于 until 循环，但在某些时候—也只是极少数情况下，until 循环更加有用。

```shell
until 条件表达式
do
    ...
done
```

## 匹配多值-case

类似于其他语言的switch-case语句

```shell
case 值 in
模式1)
	...
	;;
模式2)
	...
	;;
...
...
*)
	;;
esac
```

```shell
#! /bin/bash

a=5
case $a in
    1)
    echo "a == 1"
    ;;
    2)
    echo "a == 2"
    ;;
    *)
    echo "a不等于以上任何数"
    ;;
esac
```

> a不等于以上任何数

## 跳出循环-break，continue

`break`命令直接跳出所有循环

`continue`命令跳出本次循环，执行下一次循环

```shell
for i in 1 2 3 4
do
    if [ $i == 1 ]
    then
        continue
    elif [ $i == 3 ]
    then
        break
    fi
    echo "i == $i"
done
```

> i == 2