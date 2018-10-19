## 简介

Shell 是一个用 C 语言编写的程序，它是用户使用 Linux 的桥梁。Shell 既是一种命令语言，又是一种程序设计语言。

Shell 是指一种应用程序，这个应用程序提供了一个界面，用户通过这个界面访问操作系统内核的服务。

Ken Thompson 的 sh 是第一种 Unix Shell，Windows Explorer 是一个典型的图形界面 Shell。

## Shell 脚本

Shell 脚本（shell script），是一种为 shell 编写的脚本程序。

业界所说的 shell 通常都是指 shell 脚本，但读者朋友要知道，shell 和 shell script 是两个不同的概念。

由于习惯的原因，简洁起见，本文出现的 "shell编程" 都是指 shell 脚本编程，不是指开发 shell 自身。

Linux Shell 脚本以`.sh`结尾

## Hello World

```shell
#!/bin/bash

echo "hello world"
```

> 执行shell脚本首先要使脚本拥有可执行权限
>
> sudo chmod 775 helloworld.sh
>
> 执行shell脚本
>
>  ./helloworld.sh

`#!`是一个约定的标记，它告诉系统这个脚本需要什么解释器来执行，即使用哪一种 Shell 执行该脚本。

`echo`命令用于向窗口输出文本。

## 注释

以`#`开头的行就是注释，会被解释器忽略。

sh 里没有多行注释，只能每一行加一个#号。

## 变量

### 定义变量

```shell
变量名=变量值
```

* 变量名和值之前不能有空格
* 不用分号结尾
* 命名只能使用英文字母，数字和下划线，首个字符不能以数字开头
* 中间不能有空格，可以使用下划线（_）
* 不能使用标点符号
* 不能使用bash里的关键字（可用help命令查看保留关键字）

### 使用变量

使用一个定义过的变量，只要在变量名前面加美元符号`$`即可

```shell
echo $变量名
echo ${变量名}
```

变量名外面的花括号是可选的，加不加都行，加花括号是为了帮助解释器识别变量的边界

### 只读变量

使用 `readonly` 命令可以将变量定义为只读变量，只读变量的值不能被改变。

```shel
变量名=变量值
readonly 变量名
```

### 删除变量

使用 `unset` 命令可以删除变量。

```shell
unset 变量名
```

### 变量类型

1. 局部变量： 局部变量在脚本或命令中定义，仅在当前shell实例中有效，其他shell启动的程序不能访问局部变量。
2. 环境变量：所有的程序，包括shell启动的程序，都能访问环境变量，有些程序需要环境变量来保证其正常运行。必要的时候shell脚本也可以定义环境变量。
3. shell变量：shell变量是由shell程序设置的特殊变量。shell变量中有一部分是环境变量，有一部分是局部变量，这些变量保证了shell的正常运行

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

## 字符串

### 单引号

```shell
str='hello world'
```

* 单引号里的任何字符都会原样输出，单引号字符串中的变量是无效的
* 单引号字串中不能出现单独一个的单引号（对单引号使用转义符后也不行），但可成对出现，作为字符串拼接使用。

### 双引号

```shell
s='xx'
str="hello \"${s}\" world"
```

* 双引号里可以有变量
* 双引号里可以出现转义字符

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
hello, world ! hello, world !
hello, world ! hello, ${str} !
hello, world !hello, ${str} !
```

### 获取字符串长度

```shell
#!/bin/bash
str="hello world"
echo ${#str}
```

> 11

### 提取子字符串

```shell
#!/bin/bash
str="hello world"
echo ${str:1:4}
```

> ello

### 查找子字符串

查找字符 **i** 或 **o** 的位置(哪个字母先出现就计算哪个)

```shell
string="runoob is a great site"
echo `expr index "$string" io`  # 输出 4
```

> 4

**注意：** 以上脚本中 `` `是反引号，而不是单引号` '`

## 数组

* Bash Shell只有一维数组
* 初始化时不需要定义数组大小
* 数组元素的下标由0开始
* 数组中可以同时存在不同类型的元素

Shell 数组用`括号 ()`来表示，元素用`空格 `符号分割开

```shell
数组名=(值1 ‘值'，“值2”)
```

### 获取数组中的元素

```shell
${array_name[index]}
```

### 获取数组所有元素

使用`@` 或` *` 可以获取数组中的所有元素

```shell
${array_name[@]}
${array_name[*]}
```

### 获取数组值的个数

获取数组长度的方法与获取字符串长度的方法相同，都是使用`#`运算符

```shell
${#array_name[@]}
```

### 实例

```shell
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
```

> 1
> a
> 1 2 3 a b
> 1 2 3 a b
> 5
> 5

## 向Shell脚本传递参数

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

## 运算符

* 算术运算符
* 关系运算符
* 布尔运算符
* 字符串运算符
* 文件测试运算符

原生bash不支持简单的数学运算，但是可以通过其他命令来实现，例如 `awk` 和 `expr`，expr 最常用

`expr` 是一款表达式计算工具，使用它能完成表达式的求值操作。

```shell
#!/bin/bash

value=`expr 1 + 2`
echo "value = ${value}"
```

> value = 3

**注意：**

`expr`表达式是用反引号\`括起来的，而不是单引号`''`

表达式和运算符之间是有空格的。

### 算符运算符

假设a=10，b=20

| 运算符 | 说明                                          | 举例                          |
| ------ | --------------------------------------------- | ----------------------------- |
| +      | 加法                                          | `expr $a + $b` 结果为 30。    |
| -      | 减法                                          | `expr $a - $b` 结果为 -10。   |
| *      | 乘法                                          | `expr $a \* $b` 结果为  200。 |
| /      | 除法                                          | `expr $b / $a` 结果为 2。     |
| %      | 取余                                          | `expr $b % $a` 结果为 0。     |
| =      | 赋值                                          | `a=$b` 将把变量 b 的值赋给 a。 |
| ==     | 相等。用于比较两个数字，相同则返回 true。     | `[ $a == $b ]` 返回 false。     |
| !=     | 不相等。用于比较两个数字，不相同则返回 true。 | `[ $a != $b ]` 返回 true。      |

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

假设a=10，b=20

| 运算符 | 说明                                                  | 举例                          |
| ------ | ----------------------------------------------------- | ----------------------------- |
| -eq    | 检测两个数是否相等，相等返回 true。                   | `[ $a -eq $b ] ` 返回 false。 |
| -ne    | 检测两个数是否不相等，不相等返回 true。               | `[ $a -ne $b ]`  返回 true。      |
| -gt    | 检测左边的数是否大于右边的，如果是，则返回 true。     | `[$a -gt $b ]` 返回 false。    |
| -lt    | 检测左边的数是否小于右边的，如果是，则返回 true。     | ` $a -lt $b ` 返回 true。     |
| -ge    | 检测左边的数是否大于等于右边的，如果是，则返回 true。 | ` $a -ge $b ` 返回 false。    |
| -le    | 检测左边的数是否小于等于右边的，如果是，则返回 true。 | ` $a -le $b ` 返回 true。     |

**注意：**

`[  ]`和中间表达式有空格

### 布尔运算符

假设a=10，b=20

| 运算符 | 说明                                                | 举例                                     |
| ------ | --------------------------------------------------- | ---------------------------------------- |
| !      | 非运算，表达式为 true 则返回 false，否则返回 true。 | [ ! false ] 返回 true。                  |
| -o     | 或运算，有一个表达式为 true 则返回 true。           | [ $a -lt 20 -o $b -gt 100 ] 返回 true。  |
| -a     | 与运算，两个表达式都为 true 才返回 true。           | [ $a -lt 20 -a $b -gt 100 ] 返回 false。 |

### 字符串运算符

### 文件测试运算符

## 流程控制

与其他语言不同，Shell的流程控制块不能为空。

比如其他语言可以在`else`代码块中不写逻辑，但是`sh/bash`里不能这么写。

### 逻辑控制-if

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

### 循环-for

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

### 循环-while

```shell
while 表达式
do
	...
done
```

### 无线循环

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

## 函数



## 输入/输出



