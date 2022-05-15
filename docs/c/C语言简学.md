# C语言简学

## 简介

[维基百科](https://zh.wikipedia.org/wiki/C%E8%AF%AD%E8%A8%80)

## HelloWrold

```c
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("hello world");
    return 0;
}
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
* C 是大小写敏感的，所以变量**Person**和**person**是两个变量
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

与常量不同，存储在常量中的值在程序执行期间不可改变

在C中有两种方式定义常量

1. 使用 **#define** 预处理器
2. 使用 **const** 关键字

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

> 把常量定义为大写字母形式，是一种很好的编程习惯

## 数据类型

| 类型       | 描述                                                         |
| :--------- | ------------------------------------------------------------ |
| 基本类型   | 整数类型和浮点数类型。它们是算术类型。                       |
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

void类型指定没有可用的值。

| 类型         | 描述                                                         |
| ------------ | ------------------------------------------------------------ |
| 函数返回为空 | 不返回值的函数的返回类型为void。例如void main();             |
| 函数参数为空 | 不带参数的函数可以接受一个 void，也可以不写了。              |
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

## 标准输入输出流

C 语言把所有的设备都当作文件。文件指针是访问文件的方式。

| 标准文件 | 文件指针 | 设备     |
| -------- | -------- | -------- |
| 标准输入 | stdin    | 键盘     |
| 标准输出 | stdout   | 屏幕     |
| 标准错误 | stderr   | 您的屏幕 |

### scanf() 和 printf()函数

C 语言中的 I/O (输入/输出) 通常使用 printf() 和 scanf() 两个函数。

scanf() 函数用于从标准输入（键盘）读取并格式化， printf() 函数发送格式化输出到标准输出（屏幕）。

```c
#include <stdio.h>
int main()
{
    float f;
    printf("Enter a number: ");
    // %f 匹配浮点型数据
    scanf("%f",&f);
    printf("Value = %f", f);
    return 0;
}
```

### getchar() 和 putchar() 函数

**int getchar(void)** 函数从屏幕读取下一个可用的字符，并把它返回为一个整数。这个函数在同一个时间内只会读取一个单一的字符。您可以在循环内使用这个方法，以便从屏幕上读取多个字符。

**int putchar(int c)** 函数把字符输出到屏幕上，并返回相同的字符。这个函数在同一个时间内只会输出一个单一的字符。您可以在循环内使用这个方法，以便在屏幕上输出多个字符。

```c
#include <stdio.h>
 
int main( )
{
   int c;
 
   printf( "Enter a value :");
   c = getchar( );
 
   printf( "\nYou entered: ");
   putchar( c );
   printf( "\n");
   return 0;
}
```

当上面的代码被编译和执行时，它会等待您输入一些文本，当您输入一个文本并按下回车键时，程序会继续并只会读取一个单一的字符，显示如下：


> $./a.out
> Enter a value :runoob
>
> You entered: r

### gets() 和 puts() 函数

**char \*gets(char *s)** 函数从 **stdin** 读取一行到 **s** 所指向的缓冲区，直到一个终止符或 EOF。

**int puts(const char \*s)** 函数把字符串 s 和一个尾随的换行符写入到 **stdout**。

```c
#include <stdio.h>
 
int main( )
{
   char str[100];
 
   printf( "Enter a value :");
   gets( str );
 
   printf( "\nYou entered: ");
   puts( str );
   return 0;
}
```

当上面的代码被编译和执行时，它会等待您输入一些文本，当您输入一个文本并按下回车键时，程序会继续并读取一整行直到该行结束，显示如下：

> $./a.out
> Enter a value :runoob
> You entered: runoob


## 格式化输出



## 文件输入输出流

### 打开文件

使用 `fopen( )` 函数来创建一个新的文件或者打开一个已有的文件，这个调用会初始化类型 `FILE` 的一个结构对象，类型 **FILE** 包含了所有用来控制流的必要的信息。

```c
FILE *fopen( const char * filename, const char * mode );
```

`filename`是一个字符指针，用来定义文件名。

`mode`是文件的访问模式。

| 模式 | 描述                                                         |
| ---- | ------------------------------------------------------------ |
| r    | 打开一个已有的文本文件，允许读取文件。                       |
| w    | 打开一个文本文件，允许写入文件。如果文件不存在，则会创建一个新文件。如果文件存在，则该会被截断为零长度，重新写入。 |
| a    | 打开一个文本文件，如果文件存在，以追加模式写入文件。如果文件不存在，则会创建一个新文件。 |
| r+   | 打开一个文本文件，允许读写文件。                             |
| w+   | 打开一个文本文件，允许读写文件。如果文件已存在，则文件会被截断为零长度，如果文件不存在，则会创建一个新文件。 |
| a+   | 打开一个文本文件，允许读写文件。如果文件不存在，则会创建一个新文件。读取会从文件的开头开始，写入则只能是追加模式。 |

如果处理的是二进制文件，则需使用下面的访问模式来取代上面的访问模式：

```c
"rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"
```

### 写入文件

**写入字符：**

```c
int fputc( int c, FILE *fp );
```

* 函数 **fputc()** 把参数 c 的字符值写入到 fp 所指向的输出流中。

* 如果写入成功，它会返回写入的字符，如果发生错误，则会返回 **EOF**。

**写入字符串：**

```c
int fputs( const char *s, FILE *fp );
```

* 函数 **fputs()** 把字符串 **s** 写入到 fp 所指向的输出流中。

* 如果写入成功，它会返回一个非负值，如果发生错误，则会返回 **EOF**。

* 也可以使用 **int fprintf(FILE \*fp,const char *format, ...)** 函数来写把一个字符串写入到文件中。

### 读取文件

**读取字符：**

```c
int fgetc( FILE * fp );
```

* **fgetc()** 函数从 fp 所指向的输入文件中读取一个字符。

* 返回值是读取的字符，如果发生错误则返回 **EOF**。

**读取字符串：**

```c
char *fgets( char *buf, int n, FILE *fp );
```

* 函数 **fgets()** 从 fp 所指向的输入流中读取 n - 1 个字符。
* 它会把读取的字符串复制到缓冲区 **buf**，并在最后追加一个 **null** 字符来终止字符串。
* 如果这个函数在读取最后一个字符之前就遇到一个换行符 '\n' 或文件的末尾 EOF，则只会返回读取到的字符，包括换行符。
* 也可以使用 **int fscanf(FILE \*fp, const char *format, ...)** 函数来从文件中读取字符串，但是在遇到第一个空格字符时，它会停止读取。

### 关闭文件

```c
 int fclose( FILE *fp );
```

如果成功关闭文件，**fclose( )** 函数返回**零**，如果关闭文件时发生错误，函数返回 **EOF**。

这个函数实际上，会清空缓冲区中的数据，关闭文件，并释放用于该文件的所有内存。

`EOF` 是一个定义在头文件 **stdio.h** 中的常量。

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    //打开文件
    file = fopen("hello.txt", "w+");
    //写入文件
    int result = fputc('a', file);
    if (result != EOF)
    {
        printf("写入字符成功 result == %d\n", result);
    }
    result = fputs("hello world", file);
    if (result != EOF)
    {
        printf("写入字符串成功 result == %d\n", result);
    }
    //关闭文件
    fclose(file);
    return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    //打开文件
    file = fopen("hello.txt", "r");
    //读取文件
    int result = fgetc(file);
    if (result != EOF)
    {
        printf("读取字符成功 result == %d\n", result);
    }
    char buffer[255];
    fgets(buffer, 255, (FILE*)file);
    printf("rc == %s\n", buffer);
    //关闭文件
    fclose(file);
    return 0;
}
```

