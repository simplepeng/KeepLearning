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
