# Shell简学

## 简介

Shell 是一个用 C 语言编写的程序，它是用户使用 Linux 的桥梁。Shell 既是一种命令语言，又是一种程序设计语言。

Shell 是指一种应用程序，这个应用程序提供了一个界面，用户通过这个界面访问操作系统内核的服务。

Ken Thompson 的 sh 是第一种 Unix Shell，Windows Explorer 是一个典型的图形界面 Shell。

## shell脚本

Shell 脚本（shell script），是一种为 shell 编写的脚本程序。

业界所说的 shell 通常都是指 shell 脚本，但读者朋友要知道，shell 和 shell script 是两个不同的概念。

由于习惯的原因，简洁起见，本文出现的 "shell编程" 都是指 shell 脚本编程，不是指开发 shell 自身。

Linux Shell 脚本以`.sh`结尾

## hello world

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

## 系统变量

### 常用系统变量

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

### 显示当前shell中所有变量：set

```shell
$ set
'!'=0
'#'=0
'$'=1104
'*'=(  )
-=569JNRXZghiklms
0=-zsh
```

### 特殊变量

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

- Bash Shell只有一维数组
- 初始化时不需要定义数组大小
- 数组元素的下标由0开始
- 数组中可以同时存在不同类型的元素

Shell 数组用`括号 ()`来表示，元素用`空格 `符号分割开

```shell
数组名=(值1 '值'，"值2")
arr=(1,'a',"中国")
```

### 获取数组中的元素

```shell
${array_name[index]}

arr=(1,'a',"中国")
${arr[0]} # 1
```

### 获取数组所有元素

使用`@` 或` *` 可以获取数组中的所有元素

```shell
${array_name[@]}
${array_name[*]}

arr=(1,'a',"中国")
${arr[*]}
# 1,'a',"中国"
```

### 获取数组值的个数

获取数组长度的方法与获取字符串长度的方法相同，都是使用`#`运算符

```shell
${#array_name[@]}

arr=(1,'a',"中国")
echo ${#arr[@]}
# 3
```

### example

```shell
#!/bin/bash

arr=(1 2 3 'a' "b")
# 获取数组中的元素
echo ${arr[0]} # 1
echo ${arr[3]} # a
# 获取数组所有元素
echo ${arr[@]} # 1 2 3 a b
echo ${arr[*]} # 1 2 3 a b
# 获取数组值的个数
echo ${#arr[@]} # 5
echo ${#arr[*]} # 5
```

## 运算符

- 算术运算符
- 关系运算符
- 布尔运算符
- 字符串运算符
- 文件测试运算符

原生bash不支持简单的数学运算，但是可以通过其他命令来实现，例如 `awk` 和 `expr`，expr 最常用

`expr` 是一款表达式计算工具，使用它能完成表达式的求值操作。

```shell
#!/bin/bash

value=`expr 1 + 2`
echo "value = ${value}"
# value = 3
```

**注意：**

`expr`表达式是用反引号 \` 括起来的，而不是单引号`''`

表达式和运算符之间是有空格的。

### 算术运算符

*  `$((运算式)) `或 `$[运算式]`
* `expr`表达式

假设a=10，b=20

| 运算符 | 说明                                          | 举例                           |
| ------ | --------------------------------------------- | ------------------------------ |
| +      | 加法                                          | `expr $a + $b` 结果为 30。     |
| -      | 减法                                          | `expr $a - $b` 结果为 -10。    |
| *      | 乘法                                          | `expr $a \* $b` 结果为  200。  |
| /      | 除法                                          | `expr $b / $a` 结果为 2。      |
| %      | 取余                                          | `expr $b % $a` 结果为 0。      |
| =      | 赋值                                          | `a=$b` 将把变量 b 的值赋给 a。 |
| ==     | 相等。用于比较两个数字，相同则返回 true。     | `[ $a == $b ]` 返回 false。    |
| !=     | 不相等。用于比较两个数字，不相同则返回 true。 | `[ $a != $b ]` 返回 true。     |

```shell
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
```

> a + b = 3
> a - b = -1
> a * b = 2
> a / b = 0
> a % b = 1
> a = b : 0
> a !=b : 1
> a = 2

### 关系运算符

关系运算符只支持数字，不支持字符串，除非字符串的值是数字。

语法：[ 表达式 ]

注意：表达式前后有空格

假设a=10，b=20

| 运算符 | 说明                                                         | 举例                          |
| ------ | ------------------------------------------------------------ | ----------------------------- |
| -eq    | (equal)检测两个数是否`相等`，相等返回 true。                 | `[ $a -eq $b ] ` 返回 false。 |
| -ne    | (not equal)检测两个数是否`不相等`，不相等返回 true。         | `[ $a -ne $b ]`  返回 true。  |
| -gt    | (greater than)检测左边的数是否`大于`右边的，如果是，则返回 true。 | `[ $a -gt $b  ]` 返回 false。 |
| -lt    | (less than)检测左边的数是否`小于`右边的，如果是，则返回 true。 | `[ $a -lt $b ] ` 返回 true。  |
| -ge    | (greater equal)检测左边的数是否`大于等于`右边的，如果是，则返回 true。 | `[ $a -ge $b ]` 返回 false。  |
| -le    | (less equal)检测左边的数是否`小于等于`右边的，如果是，则返回 true。 | `[ $a -le $b ]` 返回 true。   |

**注意：**

`[  ]`和中间表达式有空格

### 布尔运算符

假设a=10，b=20

| 运算符 | 说明                                                | 举例                                       |
| ------ | --------------------------------------------------- | ------------------------------------------ |
| !      | 非运算，表达式为 true 则返回 false，否则返回 true。 | `[ ! false ] `返回 true。                  |
| -o     | 或运算，有一个表达式为 true 则返回 true。           | `[ $a -lt 20 -o $b -gt 100 ]` 返回 true。  |
| -a     | 与运算，两个表达式都为 true 才返回 true。           | `[ $a -lt 20 -a $b -gt 100 ]` 返回 false。 |

### 字符串运算符

假设字符串变量 a="abc"，b="efg"

| 运算符 | 说明                                      | 举例                       |
| ------ | ----------------------------------------- | -------------------------- |
| =      | 检测两个字符串是否相等，相等返回 true。   | `[ $a = $b ]` 返回 false。 |
| !=     | 检测两个字符串是否相等，不相等返回 true。 | `[ $a != $b ]` 返回 true。 |
| -z     | 检测字符串长度是否为0，为0返回 true。     | `[ -z $a ]` 返回 false。   |
| -n     | 检测字符串长度是否为0，不为0返回 true。   | `[ -n "$a" ]` 返回 true。  |
| $str   | 检测字符串是否为空，不为空返回 true。     | `[ $a ]` 返回 true。       |

```shell
#!/bin/bash

a="abc"
b="efg"

if [ $a = $b ]
then
   echo "$a = $b : a 等于 b"
else
   echo "$a = $b: a 不等于 b"
fi
if [ $a != $b ]
then
   echo "$a != $b : a 不等于 b"
else
   echo "$a != $b: a 等于 b"
fi
if [ -z $a ]
then
   echo "-z $a : 字符串长度为 0"
else
   echo "-z $a : 字符串长度不为 0"
fi
if [ -n "$a" ]
then
   echo "-n $a : 字符串长度不为 0"
else
   echo "-n $a : 字符串长度为 0"
fi
if [ $a ]
then
   echo "$a : 字符串不为空"
else
   echo "$a : 字符串为空"
fi
```

> abc = efg: a 不等于 b
> abc != efg : a 不等于 b
> -z abc : 字符串长度不为 0
> -n abc : 字符串长度不为 0
> abc : 字符串不为空

### 文件检测运算符

文件测试运算符用于检测 Unix 文件的各种属性

| 操作符  | 说明                                                         | 举例                        |
| ------- | ------------------------------------------------------------ | --------------------------- |
| -b file | 检测文件是否是块设备文件，如果是，则返回 true。              | `[ -b $file ]` 返回 false。 |
| -c file | 检测文件是否是字符设备文件，如果是，则返回 true。            | `[ -c $file ]` 返回 false。 |
| -d file | 检测文件是否是目录，如果是，则返回 true。                    | `[ -d $file ]` 返回 false。 |
| -f file | 检测文件是否是普通文件（既不是目录，也不是设备文件），如果是，则返回 true。 | `[ -f $file ]` 返回 true。  |
| -g file | 检测文件是否设置了 SGID 位，如果是，则返回 true。            | `[ -g $file ]` 返回 false。 |
| -k file | 检测文件是否设置了粘着位(Sticky Bit)，如果是，则返回 true。  | `[ -k $file ]` 返回 false。 |
| -p file | 检测文件是否是有名管道，如果是，则返回 true。                | `[ -p $file ]` 返回 false。 |
| -u file | 检测文件是否设置了 SUID 位，如果是，则返回 true。            | `[ -u $file ] `返回 false。 |
| -r file | 检测文件是否可读，如果是，则返回 true。                      | `[ -r $file ]` 返回 true。  |
| -w file | 检测文件是否可写，如果是，则返回 true。                      | `[ -w $file ]` 返回 true。  |
| -x file | 检测文件是否可执行，如果是，则返回 true。                    | `[ -x $file ]` 返回 true。  |
| -s file | 检测文件是否为空（文件大小是否大于0），不为空返回 true。     | `[ -s $file ]`返回 true。   |
| -e file | 检测文件（包括目录）是否存在，如果是，则返回 true。          | `[ -e $file ]` 返回 true。  |

```shell
#!/bin/bash

file="/test.sh"
if [ -r $file ]
then
   echo "文件可读"
else
   echo "文件不可读"
fi
if [ -w $file ]
then
   echo "文件可写"
else
   echo "文件不可写"
fi
if [ -x $file ]
then
   echo "文件可执行"
else
   echo "文件不可执行"
fi
if [ -f $file ]
then
   echo "文件为普通文件"
else
   echo "文件为特殊文件"
fi
if [ -d $file ]
then
   echo "文件是个目录"
else
   echo "文件不是个目录"
fi
if [ -s $file ]
then
   echo "文件不为空"
else
   echo "文件为空"
fi
if [ -e $file ]
then
   echo "文件存在"
else
   echo "文件不存在"
fi
```

> 文件可读
> 文件可写
> 文件可执行
> 文件为普通文件
> 文件不是个目录
> 文件不为空
> 文件存在

## 流程控制

### 逻辑控制-if

与其他语言不同，Shell的流程控制块不能为空。

比如其他语言可以在`else`代码块中不写逻辑，但是`sh/bash`里不能这么写。

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

### 循环遍历

#### for

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

#### while

```shell
while 表达式
do
	...
done
```

#### 无限循环

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

#### until

until 循环执行一系列命令直至条件为 true 时停止。

until 循环与 while 循环在处理方式上刚好相反。

一般 while 循环优于 until 循环，但在某些时候—也只是极少数情况下，until 循环更加有用。

```shell
until 条件表达式
do
    ...
done
```

### 跳出循环

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

### 匹配多值-case

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


## 函数

### 定义

```shell
[ function ] 函数名 [()]
{
    ...
    [return int;] 
}
```

上面的`[]`代表可选，也就是`function`关键字可以不写

函数定义必须在函数调用之前

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

### 返回值

可以显示加上`return`关键字返回参数，如果不加，将以最后一条命令运行结果，作为返回值

`return`的返回值为(0-255)的整数

函数返回值在调用该函数后通过 `$? `来获得

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

```shell
# 返回大于255的数
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

**注意:** 可以看到上面返回大于255的整数又重新从0开始计数，所以256=1，257=2

### 参数

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

**注意：**

* \$10 不能获取第十个参数，获取第十个参数需要\${10}。

* 当n>=10时，需要使用`${n}`来获取参数。

| 参数处理 | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| $#       | 传递到脚本的参数个数                                         |
| $*       | 以一个单字符串显示所有向脚本传递的参数                       |
| $$       | 脚本运行的当前进程ID号                                       |
| $!       | 后台运行的最后一个进程的ID号                                 |
| $@       | 与$*相同，但是使用时加引号，并在引号中返回每个参数。         |
| $-       | 显示Shell使用的当前选项，与set命令功能相同。                 |
| $?       | 显示最后命令的退出状态。0表示没有错误，其他任何值表明有错误。 |

### 系统函数

#### basename

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

#### dirname

语法：dirname 文件绝对路径

描述：从给定的包含绝对路径的文件名中去除文件名（非目录部分），然后返回剩下的路径（目录的部分）

```shell
dirname /home/simple/shell.txt
```

> /home/simple

## 输入/输出

### echo

`echo`指令用于输出字符串

```shell
echo string
```

* 输出普通字符串

```shell
echo "hello world"
# hello world
# 字符串的双引号可以省略
```

* 输出转义字符串

```shell
echo "\"hello world\"
# "hello world"
```

* 输出变量的值

```shell
#! /bin/bash

read var
echo "var == ${var}"
```

> sh read.sh
> hello 			# 标准输入
> var == hello	# 输出

`read `命令从标准输入中读取一行,并把输入行的每个字段的值指定给 shell 变量

* 换行\不换行

```shell
echo "hello \n"
echo "world"

echo "hello \c"
echo "world"

echo ""
echo "hello"
echo "world"
```

> hello
>
> world
> hello world
>
> hello
> world

* 输出结果重定向到文件

```shell
echo "hello world" > filename
```

* 使用单引号原样输出字符串，不转义

```shell
echo '$name\"'
# $name\"
```

* 输出命令执行结果

```shell
echo `date`
```

> 2018年10月22日 星期一 15时26分29秒 CST

**注意：**执行命令用的反引号，不是单引号

### printf

printf 命令模仿 C 程序库（library）里的 printf() 程序。

printf 由 POSIX 标准所定义，因此使用 printf 的脚本比使用 echo 移植性好。

默认 printf 不会像 echo 自动添加换行符，我们可以手动添加 \n。

```shell
printf format-string  [arguments...]
```

- **format-string:** 为格式控制字符串
- **arguments:** 为参数列表。

```shell
#! /bin/bash

printf "%s\n" "hello"
printf "%d\n" 10
printf "%c\n" 'a'
printf "%f\n" 11.11
```

> hello
> 10
> a
> 11.110000

### 重定向

| 命令            | 说明                                               |
| --------------- | -------------------------------------------------- |
| command > file  | 将输出重定向到 file。                              |
| command < file  | 将输入重定向到 file。                              |
| command >> file | 将输出以追加的方式重定向到 file。                  |
| n > file        | 将文件描述符为 n 的文件重定向到 file。             |
| n >> file       | 将文件描述符为 n 的文件以追加的方式重定向到 file。 |
| n >& m          | 将输出文件 m 和 n 合并。                           |
| n <& m          | 将输入文件 m 和 n 合并。                           |
| << tag          | 将开始标记 tag 和结束标记 tag 之间的内容作为输入。 |

**注意：**文件描述符 `0 `通常是`标准输入（STDIN）`，`1` 是`标准输出（STDOUT`），`2 `是`标准错误输出（STDERR）`

#### /dev/null 文件

如果希望执行某个命令，但又不希望在屏幕上显示输出结果，那么可以将输出重定向到 /dev/null

```shell
$ command > /dev/null
```

/dev/null 是一个特殊的文件，写入到它的内容都会被丢弃。

如果尝试从该文件读取内容，那么什么也读不到。

但是 /dev/null 文件非常有用，将命令的输出重定向到它，会起到"禁止输出"的效果。如果希望屏蔽 stdout 和 stderr，可以这样写：

```shell
# 如果希望屏蔽 stdout 和 stderr，可以这样写：
command > /dev/null 2>&1
# 0 是标准输入（STDIN），
# 1 是标准输出（STDOUT），
# 2 是标准错误输出（STDERR）
```

## 传递参数

我们可以在执行 Shell 脚本时，向脚本传递参数，脚本内获取参数的格式为：`$n`或`${n}`。

`n` 代表一个数字，0为执行的文件名，1 为执行脚本的第一个参数，2 为执行脚本的第二个参数，以此类推……

```shell
#! /bin/bash

echo "执行文件名 = $0"
echo "执行文件名 = ${0}"

echo "第一个参数 = $1"
echo "第一个参数 = ${1}"
```

> ./shell_arg.sh l f
>
> 执行文件名 = ./shell_arg.sh
> 执行文件名 = ./shell_arg.sh
> 第一个参数 = l
> 第一个参数 = l

## 文件包含

和其他语言一样，Shell 也可以包含外部脚本。

这样可以很方便的封装一些公用的代码作为一个独立的文件。

```shell
. filename  # 注意点号(.)和文件名中间有一空格
或
source filename
```

* include1.sh

```shell
#!/bin/bash

url="www.simplepeng.com"
```

* include2.sh

```shell
#!/bin/bash

#. include1.sh
#. ./include.sh

source include1.sh
#source ./include1.sh

echo "网址 == $url"
```

> 网址 == www.simplepeng.com

## 工具

### cut

cut命令从文件的每一行剪切字节、字符和字段并将这些字节、字符和字段输出。

基本用法：cut [选项参数] filename

说明：默认分隔符是制表符

选项参数说明：

| 选项参数 | 功能                         |
| -------- | ---------------------------- |
| -f       | 列号，提取第几列             |
| -d       | 分隔符，按照指定分隔符分割列 |

```shell
//cut.txt
dong shen
guan zhen
wo  wo
lai  lai
le  le
```

```shell
cut -d " " -f 1 cut.txt
```

> dong
>
> guan
>
> wo
>
> lai
>
> le

### sed

sed是一种`流`编辑器，它一次处理一行内容。处理时，把当前处理的行存储在临时缓冲区中，称为“模式空间”，接着用sed命令处理缓冲区中的内容，处理完成后，把缓冲区的内容送往屏幕。接着处理下一行，这样不断重复，直到文件末尾。**文件内容并没有改变**，除非你使用重定向存储输出。

基本用法：sed [选项参数] ‘command’ filename

选项参数说明：

| 选项参数 | 功能                                |
| -------- | ----------------------------------- |
| -e       | 直接在指令列模式上进行sed的动作编辑 |

命令功能描述：

| 命令 | 功能描述                                |
| ---- | --------------------------------------- |
| a    | 新增，a的后面可以接字符串，在下一行出现 |
| d    | 删除                                    |
| s    | 查找并替换                              |