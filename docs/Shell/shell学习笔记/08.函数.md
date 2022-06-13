# 函数

## 函数定义

```shell
[ function ] 函数名 [()]
{
    ...
    [return int;] 
}
```

上面的`[]`代表可选

函数定义必须在函数调用之前、

```shell
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
```

## 函数返回值

可以显示加上`return`关键字返回参数，如果不加，将以最后一条命令运行结果，作为返回值。

`return`的返回值为(0-255)的整数

函数返回值在调用该函数后通过 `$? `来获得。

```shell
fun_return()
{
    echo "函数 fun_return 执行"
    return 0
}

fun_return
echo "函数返回值 == $?"
```

> 函数 fun_return 执行
> 函数返回值 == 0

返回大于255的数

```shell
fun_return()
{
    echo "函数 fun_return 执行"
    return 257
}

fun_return
echo "函数返回值 == $?"
```

> 函数 fun_return 执行
> 函数返回值 == 1

**注意：**可以看到上面返回大于255的整数又重新从0开始计数，所以256=1，257=2

## 函数参数

在Shell中，调用函数时可以向其传递参数。在函数体内部，通过 `$n` 的形式来获取参数的值。

`$*` 取出所有参数

`$0`取出的是文件名

例如，`$1`表示第一个参数，`$2`表示第二个参数...

```shell
#! /bin/bash

fun_arg()
{
    echo "第0个参数 ==  $0 "
    echo "第1个参数 ==  $1 "
    echo "第2个参数 ==  $2 "
    echo "所有参数 ==  $* "
}

fun_arg 1 2 3 4 5
```

> 第0个参数 ==  fun_arg.sh
> 第1个参数 ==  1
> 第2个参数 ==  2
> 所有参数 ==  1 2 3 4 5

**注意：**\$10 不能获取第十个参数，获取第十个参数需要\${10}。

​		当n>=10时，需要使用`${n}`来获取参数。

| 参数处理 | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| $#       | 传递到脚本的参数个数                                         |
| $*       | 以一个单字符串显示所有向脚本传递的参数                       |
| $$       | 脚本运行的当前进程ID号                                       |
| $!       | 后台运行的最后一个进程的ID号                                 |
| $@       | 与$*相同，但是使用时加引号，并在引号中返回每个参数。         |
| $-       | 显示Shell使用的当前选项，与set命令功能相同。                 |
| $?       | 显示最后命令的退出状态。0表示没有错误，其他任何值表明有错误。 |

## 系统函数

### basename函数

语法：basename \[string/ pathname] [suffix]

描述：basename命令会删除所有的前缀包括最好一个`/`字符，然后将字符串显示出来

选项：suffix为后缀，如果suffix被指定，basename会将pathname或string中的suffix去掉。

```shell
basename /home/shell.txt
basename /home/shell.txt .txt
```

> shell.txt
>
> shell

### dirname函数

语法：dirname 文件绝对路径

描述：从给定的包含绝对路径的文件名中去除文件名（非目录部分），然后返回剩下的路径（目录的部分）

```shell
dirname /home/simple/shell.txt
```

> /home/simple

