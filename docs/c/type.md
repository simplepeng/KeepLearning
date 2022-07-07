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