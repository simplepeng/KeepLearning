# 数据类型

* 计算机中最小的储存单元是`位(bit)`，可以存储0或1.
* `字节(byte)`是常用的计算机储存单位，对于几乎所有的机器，`1字节均为8位`。

| 类型       | 描述                                                         |
| :--------- | ------------------------------------------------------------ |
| 基本类型   | 整数类型和浮点数类型，它们是算术类型。                       |
| 枚举类型   | 被用来定义在程序中只能赋予其一定的离散整数值的变量。它也是算术类型。 |
| voide 类型 | 类型说明符 *void* 表明没有可用的值                           |
| 派生类型   | 指针类型、数组类型、结构类型、共用体类型和函数类型           |

* C语言的算术类型都有`有符号（signed）`和`无符号（unsigned）`两种表达形式。
* 有符号的变量定义的时候signed关键字可以省略。

## 整数类型

`整数`是没有小数部分的数，`正整数`，`负整数`都是整数。

1. char
2. short
3. int
4. long

* 在C语言中，用`单引号`括起来的单个字符被称为`字符常量(character constant)`

```c
char grade = 'A'; //ASCII码=65
```

## 浮点数类型

`浮点数`与数学中`实数`的概念差不多。

1. float
2. double
3. long double

| 类型        | 存储大小 | 值范围                 | 精度      |
| ----------- | -------- | ---------------------- | --------- |
| float       | 4 字节   | 1.2E-38 到 3.4E+38     | 6 位小数  |
| double      | 8 字节   | 2.3E-308 到 1.7E+308   | 15 位小数 |
| long double | 16 字节  | 3.4E-4932 到 1.1E+4932 | 19 位小数 |

## void类型

void类型指定没用可用的值。

| 类型         | 描述                                                         |
| ------------ | ------------------------------------------------------------ |
| 函数返回为空 | 不返回值的函数的返回类型为void。例如void main();             |
| 函数参数为空 | 不带参数的函数可以接受一个 void。也可以不写了。              |
| 指针指向void | 类型为 **void *** 的指针代表对象的地址，而不是类型。例如，内存分配函数 **void \*malloc( size_t size );** 返回指向 void 的指针，可以转换为任何数据类型。 |

## sizeof函数

* `sizeof函数`是C语言的内置运算符，以字节为单位的给出指定类型的大小。
* C99和C11提供`%zd`转换说明匹配sizeof的返回类型，一些不支持C99和C11的编译器可用`%u`或`%lu`代替`%zd`。

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    printf("type char size == %lu\n", sizeof(char));
    printf("type short size == %lu\n", sizeof(short));
    printf("type int size == %lu\n", sizeof(int));
    printf("type float size == %lu\n", sizeof(float));
    printf("type long size == %lu\n", sizeof(long));
    printf("type double size == %lu\n", sizeof(double));
    printf("type long double size == %lu\n", sizeof(long double));
   
    return 0;
}
```

## 强制类型转换

* `强制类型转换(cast)`是把变量从一种类型转换为另一种数据类型。
* 圆括号和它括起来的类型名构成了`强制类型转换运算符(cast operator)`

```c
类型 变量 = (类型)变量;
```

```c
double b = 1.1;
int a = (int)b;
```