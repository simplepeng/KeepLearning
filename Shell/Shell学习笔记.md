## 简介

Shell 是一个用 C 语言编写的程序，它是用户使用 Linux 的桥梁。Shell 既是一种命令语言，又是一种程序设计语言。

Shell 是指一种应用程序，这个应用程序提供了一个界面，用户通过这个界面访问操作系统内核的服务。

Ken Thompson 的 sh 是第一种 Unix Shell，Windows Explorer 是一个典型的图形界面 Shell。

### shell脚本

Shell 脚本（shell script），是一种为 shell 编写的脚本程序。

业界所说的 shell 通常都是指 shell 脚本，但读者朋友要知道，shell 和 shell script 是两个不同的概念。

由于习惯的原因，简洁起见，本文出现的 "shell编程" 都是指 shell 脚本编程，不是指开发 shell 自身。

Linux Shell 脚本以`.sh`结尾

### hello world

```shell
#!/bin/bash

echo "hello world"
```

>执行shell脚本首先要使脚本拥有可执行权限
>
>sudo chmod 775 helloworld.sh
>
>执行shell脚本
>
>./helloworld.sh
>
>或者
>
>sh helloworld.sh //这种方式不需要修改可执行权限

`#!`是一个约定的标记，它告诉系统这个脚本需要什么解释器来执行，即使用哪一种 Shell 执行该脚本。

`echo`命令用于向窗口输出文本。

## 注释

以`#`开头的行就是注释，会被解释器忽略。

sh 里没有多行注释，只能每一行加一个`#`号。

## 变量

### 变量类型

* 局部变量： 局部变量在脚本或命令中定义，仅在当前shell实例中有效，其他shell启动的程序不能访问局部变量。
* 环境变量：所有的程序，包括shell启动的程序，都能访问环境变量，有些程序需要环境变量来保证其正常运行。必要的时候shell脚本也可以定义环境变量

* shell变量：shell变量是由shell程序设置的特殊变量。shell变量中有一部分是环境变量，有一部分是局部变量，这些变量保证了shell的正常运行

### 定义变量

```shell
变量名=变量值
```

- 变量名和值之间不能有空格
- 不用分号结尾
- 命名只能使用英文字母，数字和下划线，首个字符不能以数字开头
- 中间不能有空格，可以使用下划线（_）
- 不能使用标点符号
- 不能使用bash里的关键字（可用help命令查看保留关键字

### 使用变量

使用一个定义过的变量，只要在变量名前面加美元符号`$`即可

```shell
echo $变量名
echo ${变量名}

a=1
echo $a
```

变量名外面的花括号是可选的，加不加都行，加花括号是为了帮助解释器识别变量的边界

### 只读变量

使用 `readonly` 命令可以将变量定义为只读变量，只读变量的值不能被改变。

```shell
变量名=变量值
readonly 变量名
```

### 删除变量

使用 `unset` 命令可以删除变量。

```shell
unset 变量名
```

```shell
#!/bin/bash

a=1
b="b"
readonly c=3

echo $a
echo ${b}
echo $c
c=4
```

> 1
> b
> 3
> ./var.sh: line 10: c: readonly variable

### 系统变量

#### 常用系统变量

`$HOME`、`$PWD`、`$SHELL`、`$USER`等

```shell
#!/bin/bash

echo $HOME
echo $PWD
echo $SHELL
echo $USER
```

>/Users/simple
>/Users/simple/Desktop/WorkSpace/KeepLearning/Shell/3.变量
>/bin/zsh
>simple

#### 显示当前shell中所有变量：set

```shell
$ set
'!'=0
'#'=0
'$'=1104
'*'=(  )
-=569JNRXZghiklms
0=-zsh
```

#### 特殊变量

`$n` ：n为数字，`$0`代表该脚本名称，`$1-$9`代表第一到第九个参数，十以上的参数需要用大括号包含，`${10}`

`$#` ：获取所有输入参数的个数，常用于循环。

`$*`：这个变量代表命令行中所有的参数，`$*`把所有参数看成一个整体。

`$@`：这个变量也代表命令行中所有的参数，`$@`把每个参数区分对待。

`$?` ：最后一次执行的命令的返回状态，如果这个变量的值为0，证明上一次命令正确执行。如果这个变量的值为非0（具体是哪个数，由命令自己来决定），则证明上一个命令执行不正确了。

## 字符串

### 单引号

```shell
str='hello world'
```

- 单引号里的任何字符都会原样输出，单引号字符串中的变量是无效的
- 单引号字串中不能出现单独一个的单引号（对单引号使用转义符后也不行），但可成对出现，作为字符串拼接使用

### 双引号

```shell
s='xx'
str="hello \"${s}\" world"
```

- 双引号里可以有变量
- 双引号里可以出现转义字符

### 字符串拼接

```shell
#！/bin/bash

str="world"
# 使用双引号拼接
str1="hello, "$str" !"
str2="hello, ${str} !"
echo $str1 $str2
# 使用单引号拼接
str3='hello, '$str' !'
str4='hello, ${str} !'
echo $str3  $str4
# 新字符串为拼接的字符串
str5=$str1$str4
echo $str5
```

```shell
# output
hello, world ! hello, world !
hello, world ! hello, ${str} !
hello, world !hello, ${str} !
```

### 字符串长度

获取字符串长度用`#`

```shell
#!/bin/bash
str="hello world"
echo ${#str}
```

```shell
# output
11
```

### 提取子字符串

```shell
#!/bin/bash
str="hello world"
echo ${str:1:4}
```

```shell
# output
ello
```

### 查找子字符串

查找字符 **i** 或 **o** 的位置(哪个字母先出现就计算哪个)

```shell
string="runoob is a great site"
echo `expr index "$string" io`  
# 输出 4
```

注意：** 以上脚本中 `` `是反引号，而不是单引号` '`

## 数组

## 运算符

## 流程控制

## 函数

## 传递参数

## 文件包含

## 工具

