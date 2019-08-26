# 运算符

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

## 算术运算符

### 基本语法

1. `$((运算式)) `或 `$[运算式]`
2. `expr`表达式

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

## 关系运算符

关系运算符只支持数字，不支持字符串，除非字符串的值是数字。

语法：[ 表达式 ]

注意：表达式前后有空格

假设a=10，b=20

| 运算符 | 说明                                                  | 举例                          |
| ------ | ----------------------------------------------------- | ----------------------------- |
| -eq    | (equal)检测两个数是否`相等`，相等返回 true。       | `[ $a -eq $b ] ` 返回 false。 |
| -ne    | (not equal)检测两个数是否`不相等`，不相等返回 true。  | `[ $a -ne $b ]`  返回 true。      |
| -gt    | (greater than)检测左边的数是否`大于`右边的，如果是，则返回 true。 | `[ $a -gt $b  ]` 返回 false。  |
| -lt    | (less than)检测左边的数是否`小于`右边的，如果是，则返回 true。 | `[ $a -lt $b ] ` 返回 true。 |
| -ge    | (greater equal)检测左边的数是否`大于等于`右边的，如果是，则返回 true。 | `[ $a -ge $b ]` 返回 false。 |
| -le    | (less equal)检测左边的数是否`小于等于`右边的，如果是，则返回 true。 | `[ $a -le $b ]` 返回 true。   |

**注意：**

`[  ]`和中间表达式有空格

## 布尔运算符

假设a=10，b=20

| 运算符 | 说明                                                | 举例                                       |
| ------ | --------------------------------------------------- | ------------------------------------------ |
| !      | 非运算，表达式为 true 则返回 false，否则返回 true。 | `[ ! false ] `返回 true。                  |
| -o     | 或运算，有一个表达式为 true 则返回 true。           | `[ $a -lt 20 -o $b -gt 100 ]` 返回 true。  |
| -a     | 与运算，两个表达式都为 true 才返回 true。           | `[ $a -lt 20 -a $b -gt 100 ]` 返回 false。 |

## 字符串运算符

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

> 
abc = efg: a 不等于 b
abc != efg : a 不等于 b
-z abc : 字符串长度不为 0
-n abc : 字符串长度不为 0
abc : 字符串不为空


## 文件测试运算符

文件测试运算符用于检测 Unix 文件的各种属性。

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

>文件可读
>文件可写
>文件可执行
>文件为普通文件
>文件不是个目录
>文件不为空
>文件存在
