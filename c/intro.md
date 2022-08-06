# 简介

* C 语言是一种通用的、面向过程式的计算机程序设计语言。
* 1972 年，为了移植与开发 UNIX 操作系统，丹尼斯·里奇在贝尔电话实验室设计开发了 C 语言。
* C 语言是一种广泛使用的计算机语言，它与 Java 编程语言一样普及，二者在现代软件程序员之间都得到广泛使用。


## HelloWorld

```c
#include <stdio.h> // 预处理指令，包含另一个文件
 
int main() //入口方法，第一个被调用的函数
{
   printf("Hello, World! \n"); //输出语句
   
   return 0; //函数返回值
}
```

* `#incluce`是一条C预处理指令(preprocessor directive)。
* 通常，C编译器在编译前会对源代码做一些准备工作，即`预处理(preprocessing)`
* 这种在C程序顶部的信息结合被称为`头文件(header)`，通常以`.h`结尾