# C语言学习笔记

C 语言是一种通用的、面向过程式的计算机程序设计语言。1972 年，为了移植与开发 UNIX 操作系统，丹尼斯·里奇在贝尔电话实验室设计开发了 C 语言。

C 语言是一种广泛使用的计算机语言，它与 Java 编程语言一样普及，二者在现代软件程序员之间都得到广泛使用。

当前最新的 C 语言标准为 C18 ，在它之前的 C 语言标准有 C17、C11...C99 等。

## HelloWorld

```c
#include <stdio.h>
 
int main()
{
   printf("Hello, World! \n");
   
   return 0;
}
```

## 注释

```c
/* 单行注释 */

/* 
 多行注释
 多行注释
 多行注释
 */
```

## 数据类型

| 类型       | 描述                                                         |
| :--------- | ------------------------------------------------------------ |
| 基本类型   | 整数类型和浮点数类型，它们是算术类型。                       |
| 枚举类型   | 被用来定义在程序中只能赋予其一定的离散整数值的变量。它也是算术类型。 |
| voide 类型 | 类型说明符 *void* 表明没有可用的值                           |
| 派生类型   | 指针类型、数组类型、结构类型、共用体类型和函数类型           |

C语言的算术类型都有`有符号（signed）`和`无符号（unsigned）`两种表达形式。有符号的变量定义的时候signed关键字可以省略。

### 整数类型

1. char
2. short
3. int
4. long

### 浮点数类型

1. float
2. double
3. long double

| 类型        | 存储大小 | 值范围                 | 精度      |
| ----------- | -------- | ---------------------- | --------- |
| float       | 4 字节   | 1.2E-38 到 3.4E+38     | 6 位小数  |
| double      | 8 字节   | 2.3E-308 到 1.7E+308   | 15 位小数 |
| long double | 16 字节  | 3.4E-4932 到 1.1E+4932 | 19 位小数 |

### void类型

void类型指定没用可用的值。

| 类型         | 描述                                                         |
| ------------ | ------------------------------------------------------------ |
| 函数返回为空 | 不返回值的函数的返回类型为void。例如void main();             |
| 函数参数为空 | 不带参数的函数可以接受一个 void。也可以不写了。              |
| 指针指向void | 类型为 **void *** 的指针代表对象的地址，而不是类型。例如，内存分配函数 **void \*malloc( size_t size );** 返回指向 void 的指针，可以转换为任何数据类型。 |

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

### 强制类型转换

强制类型转换是把变量从一种类型转换为另一种数据类型。

```c
类型 变量 = (类型)变量;
```

```c
double b = 1.1;
int a = (int)b;
```

## 变量

变量是一个数据存储位置，其值在程序执行期间可以改变

```c
//声明变量
变量类型 变量名;
//变量赋值
变量名 = 值;
```

* 变量的名称可以由字母、数字和下划线字符组成
* 数字不能作为变量名开始
* C是大小写敏感的，所以变量**Person**和**person**是两个变量
* 尽量遵循驼峰命名法
* 关键字不能作为变量名

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a;
    a = 1;
    printf("a == %d\n", a);
    char b = 'c';
    printf("a == %d\n", b);
    return 0;
}
```

## 常量

与变量不同，存储在常量中的值在程序执行期间不可改变。这些固定的值，又叫做`字面量`。

在C中有两种方式定义常量

1. 使用 `#define` 预处理器
2. 使用 `const` 关键字

```c
#include <stdio.h>

#define PI 3.14

int main(int argc, char const *argv[])
{
    printf("PI == %f\n", PI);
    //PI = 3.15; error: expression is not assignable
    return 0;
}
```

```c
#include <stdio.h>

const double PI = 3.14;

int main(int argc, char const *argv[])
{
    printf("PI == %f\n",PI);  
    //PI = 3.15;  error: cannot assign to variable 'PI' with const-qualified type 'const double'
    return 0;
}
```

注：把常量定义为大写字母形式，是一种很好的编程习惯

## 函数

函数是一组一起执行一个任务的语句。每个 C 程序都至少有一个函数，即主函数 `main()`。

```c
返回类型 函数名(参数列表)
{
  //一系列执行语句
}
```

```c
int max(int num1,int num2)
{
  int result;
  if(num1 > num2)
  {
    result = num1; 
  }else
  {
    result = num2;
  }
  return result;
}
```

## 变量作用域

* 局部变量：在函数内定义的参数
* 全局变量：在所有函数外定义的参数

## 位运算

* 计算机最基本的存储单元。

* 位是数据存储的最小的单元，且只可能有两个值：`0`和`1`。

* 位运算只能用于整形：char，int和long。

### 移位运算符

| 运算符 | 描述       |
| ------ | ---------- |
| `<<`   | 左移运算符 |
| `>>`   | 右移运算符 |

在某事情况下，使用移位运算符可以将整数变量乘以和除以2的n次方。

整数左移n位相当于将该整数乘以2的n次方。

整数右移n位相当于将该整数除以2的n次方。

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 8;
    a = a << 1;        //8*2的一次方
    printf("%d\n", a); //16
    a = a << 2;        //8*2的二次方
    printf("%d\n", a); //32

    int b = 8;
    b = b >> 1;        //8 / 2的一次方
    printf("%d\n", b); //4
    b = b >> 2;        //8 / 2的一次方
    printf("%d\n", b); //1
    return 0;
}
```

### 按位逻辑运算符

按位逻辑运算符也属于二元运算符，根据两个运算对象对应的位，将结果的位设置为0或1。

| 运算符 | 操作       | 描述                                                         |
| ------ | ---------- | ------------------------------------------------------------ |
| `&`    | 按位`与`   | 只有当两个运算对象对应位都为1时，才将位结果设置为1；否则为0。**按位与**运算符用于关闭和清除值中的一个或多个位。 |
| `|`    | 按位`或`   | 只有当两个运算对象对应位都为0时，才将位结果设置为0；否则为1。**按位或**运算符用于打开和设置值中的一个或多个位。 |
| `^`    | 按位`异或` | 只有当两个运算对象相应的位不同时（即，一个是1，一个是0），**按位异或**才将位的结果设置为1；否则为0。 |

### 求反运算符

求反运算符也是一元运算符，求反运算符用于把运算对象的每一位反转，即所有的0变成1，所有的1变成0。

```c
254 -> 二进制是1111110
~254 //对254求反等于1
1 -> 0000001
```

## 

## 结构体

```c
struct Preson{
    char* name;
    int age;
};

int main()
{
    struct Person person;
    person.age = 25;
    printf("%d\n", person.age);//25
}
```

* 结构体括号结尾要带上分号`;`

### typedef简写结构体

```c
typedef struct
{
    char* name;
    int age;
} Person;

//或
typedef struct _Person
{
    char* name;
    int age;
} Person;

int main()
{
    Person person;
    person.age = 25;
    printf("%d\n", person.age);//25
}
```

### 结构体指针

```c
#include <stdio.h>

typedef struct _Person
{
    char *name;
} Person;

int main(int argc, char const *argv[])
{
    Person *p;
    Person person;
    person.name = "zhang san";
    printf("%s\n", person.name);
    p = &person;
    //两种方式访问结构指针的值
    p->name = "li si";
    printf("%s\n", (*p).name);
    return 0;
}
```

结构体作为函数参数

1. 直接传递结构体给函数

```c
typedef struct _Person
{
    char *name;
} Person;

void fun1(Person person);

int main(int argc, char const *argv[])
{
    Person p;
    p.name = "zhang san";
    printf("start -- %s\n", p.name);
    fun1(p);
    printf("end --%s\n", p.name);
    return 0;
}

void fun1(Person p)
{
    p.name = "li si";
}
```

> start -- zhang san
> end --zhang san

2. 传递结构体指针给函数

```c
#include <stdio.h>

typedef struct _Person
{
    char *name;
} Person;

void fun2(Person *person);

int main(int argc, char const *argv[])
{
    Person p;
    p.name = "zhang san";
    printf("start -- %s\n", p.name);
    fun2(&p);
    printf("end --%s\n", p.name);
    return 0;
}

void fun2(Person *p)
{
    p->name = "li si";
}
```

> start -- zhang san
> end --li si

### 结构体长度

结构体的长度一般为结构中字段长度的总和。

```c
#include <stdio.h>

typedef struct _Person
{
    int age;
} Person;

int main(int argc, char const *argv[])
{
    Person p;
    p.age = 18;
    printf("%lu\n", sizeof(p));
    return 0;
}
```

### const的结构指针

const后的指针不能修改所指向地址的值，结构指针也是一样。但是可以重新指向其他的地址。

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    const int *p;
    int a = 10;
    p = &a;
    printf("%d\n", *p);//10

    *p = 11;//编译报错 error: read-only variable is not assignable

    int b = 12;
    p = &b;
    printf("%d\n", *p);//12
    
    return 0;
}
```

### 结构体增加函数

```c
#include <stdio.h>

typedef struct
{
    void (*eat)();
} Person;

void eat()
{
    printf("%s\n", "每次多吃一粒米");
}

int main(int argc, char const *argv[])
{
    Person p;
    p.eat = &eat;
    p.eat();
    
    //指针方式
    // Person *p1;
    // p1 = &p;
    // p1->eat = &eat;
    // p1->eat();
    return 0;
}
```

## 枚举

枚举是 C 语言中的一种基本数据类型，它可以让数据更简洁，更易读。

### 定义枚举

```c
enum 枚举名
{
    枚举元素,
    枚举元素,
    枚举元素,
    ...
}
```

第一个枚举成员的默认值为整型的 0，后续枚举成员的值在前一个成员上加 1。

```c
#include <stdio.h>

enum Color
{
    red,
    blue
};

int main(int argc, char const *argv[])
{
    enum Color color;
    color = red;
    printf("corlor == %d\n", color);//corlor == 0
    color = blue;
    printf("corlor == %d\n", color);//corlor == 1
    return 0;
}
```

在C 语言中，枚举类型是被当做 int 或者 unsigned int 类型来处理的。

### 自定义枚举元素的值

```c
#include <stdio.h>

enum Color
{
    red = 10,
    blue = 22
};

int main(int argc, char const *argv[])
{
    enum Color color;
    color = red;
    printf("corlor == %d\n", color); //corlor == 10
    color = blue;
    printf("corlor == %d\n", color); //corlor == 22
    return 0;
}
```

## 数组

* 数组是一种数据结构，可以存储一个固定大小的相同类型元素的顺序集合。

* 数组都是由连续的内存位置组成。最低的地址对应第一个元素，最高的地址对应最后一个元素。

### 声明数组

```c
类型 数组名[包含元素的个数];
```

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};
    int arr1[] = {1, 2, 3, 4};

    printf("arr[0] == %d\n", arr[0]);
    printf("arr1[0] == %d\n", arr1[0]);
    return 0;
}
```

```c
//输出
arr[0] == 1
arr1[1] == 2
```

### 数组元素个数

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    printf("arr size == %d\n", size);//arr size == 5
    return 0;
}
```

## 指针

指针是存储其他变量`地址`的变量。

### 声明指针

```c
类型名 *指针名;
```

`星号(*)`是间接运算符(indirection operator)，表明指针名是一个指向类型名类型的指针，不是类型名类型的变量。

```c
int *a;
```

### 初始化指针

```c
指针 = &变量;
```

```c
int b = 10;
a = &b;
```

取址运算符(&)获取变量的内存地址，并将其放入指针变量中。

通过变量名访问变量的内容，称之为**直接访问(direct access)**

通过指向变量的指针访问变量的内容，称为**间接访问(indirect)**或**间接取值(indirecion)**

**指针名**输出的是指向变量的内存地址，***指针名**输出的指向变量存储的值

内存中每个字节都有唯一的地址，因此，多字节变量实际占用了多个地址，变量的地址是它占用字节的首地址（最低位的地址）

### 函数指针

函数指针是指向函数的指针变量。

```c
#include <stdio.h>

void (*add)(int, int);

void addImp(int x, int y)
{
    printf("sum == %d\n", x + y);
}

int main(int argc, char const *argv[])
{
    add = &addImp;
    add(2, 3);
    return 0;
}
```

输出：

```c
sum == 5
```

### 空指针

在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。

赋为 NULL 值的指针被称为**空**指针。

NULL 指针是一个定义在标准库中的值为零的常量。

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *pointNull = NULL;
    printf("pointNull 的地址是 %p\n", pointNull);//pointNull 的地址是 0x0
    return 0;
}
```

### Void指针

void指针泛指为通用指针（generic pointer），即指向任意数据对象类型的指针。

```c
void *指针名；
```

void指针最常见的用途就是声明函数的参数。如果希望一个函数能处理不同类型的参数，便可将void指针作为函数的参数。

要使用void指针必须使用**强制类型转换**

```c
(type *)指针名;
```

```c
#include <stdio.h>

void printVoid(void *value, int position)
{
    switch (position)
    {
    case 1:
        printf("value == %d\n", *((int *)value));
        break;
    case 2:
        printf("value == %ld\n", *((long *)value));
        break;
    case 3:
        printf("value == %f\n", *((float *)value));
        break;
    }
}

int main(int argc, char const *argv[])
{
    int a = 10;
    printVoid(&a, 1);
    long b = 110;
    printVoid(&b, 2);
    float c = 3.14;
    printVoid(&c, 3);
    return 0;
}
```

输出结果：

> value == 10
> value == 110
> value == 3.140000

## 字符串

在 C 语言中，字符串实际上是使用 **null** 字符 **'\0'** 终止的一维字符数组。

```c
char hello[6] = {'h','e','l','l','o','\0'};
```

其实，不需要把`null`字符放在字符串常量的末尾。C 编译器会在初始化数组时，自动把 '\0' 放在字符串的末尾。

```c
char hello[] = "hello";
```

还可以使用指针来初始化字符串

```c
char *hello = "hello";
```

C语言中有大量操作字符串的函数，都放在**string.h**头文件中

| 函数                | 描述                                                         |
| :------------------ | ------------------------------------------------------------ |
| **strcpy(s1, s2);** | 复制字符串 s2 到字符串 s1                                    |
| **strcat(s1, s2);** | 连接字符串 s2 到字符串 s1 的末尾                             |
| **strlen(s1);**     | 返回字符串 s1 的长度                                         |
| **strcmp(s1, s2);** | 如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0 |
| **strchr(s1, ch);** | 返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置     |
| **strstr(s1, s2);** | 返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置   |

```c
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str1[12] = "hello";
    char str2[12] = "world";

    //复制字符串
    char str3[12];
    strcpy(str3, str1);
    printf("%s\n", str3); //hello
    //连接字符串
    strcat(str1, str2);
    printf("%s\n", str1); //helloworld
    return 0;
}
```

```c
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char hello[] = "hello";
    printf("%s\n", hello);//hello

    printf("str len == %lu\n",strlen(hello));//str len == 5

    int realLen = sizeof(hello) / sizeof(char);
    printf("realLen == %d\n",realLen);//realLen == 6
    return 0;
}
```

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *str = "hello";
    printf("str == %s\n", str);//hello

    //用指针表示的字符串不能修改，但是用字符数组的可以修改
    //str[0] = 'w';//bus error
    //printf("str == %s\n", str);
    char strArr[] = "hello";
    strArr[0] = 'w';
    printf("&strArr == %s\n",strArr);//wello

    char *str1 = "hello";
    printf("&str == %p\n",&str);//0x7ffee88f4a08
    printf("&str1 == %p\n",&str1);//0x7ffee88f4a00
    return 0;
}
```

## Reference

* [菜鸟教程](https://www.runoob.com/cprogramming/c-tutorial.html)
