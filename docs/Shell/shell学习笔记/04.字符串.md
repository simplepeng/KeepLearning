# 字符串

## 单引号

```shell
str='hello world'
```

* 单引号里的任何字符都会原样输出，单引号字符串中的变量是无效的
* 单引号字串中不能出现单独一个的单引号（对单引号使用转义符后也不行），但可成对出现，作为字符串拼接使用。

## 双引号

```shell
s='xx'
str="hello \"${s}\" world"
```

* 双引号里可以有变量
* 双引号里可以出现转义字符

## 字符串拼接

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

## 获取字符串长度

```shell
#!/bin/bash
str="hello world"
echo ${#str}
```

> 11

## 提取子字符串

```shell
#!/bin/bash
str="hello world"
echo ${str:1:4} # 输出 ello
```

## 查找子字符串

查找字符 **i** 或 **o** 的位置(哪个字母先出现就计算哪个)

```shell
string="runoob is a great site"
echo `expr index "$string" io`  # 输出 4
```

**注意：** 以上脚本中 `` `是反引号，而不是单引号` '`