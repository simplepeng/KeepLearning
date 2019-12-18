# C++学习笔记

## 简介

C++ 是一种静态类型的、编译式的、通用的、大小写敏感的、不规则的编程语言，支持过程化编程、面向对象编程和泛型编程。

C++ 被认为是一种**中级**语言，它综合了高级语言和低级语言的特点。

C++ 是由 Bjarne Stroustrup 于 1979 年在新泽西州美利山贝尔实验室开始设计开发的。C++ 进一步扩充和完善了 C 语言，最初命名为带类的C，后来在 1983 年更名为 C++。

C++ 是 C 的一个超集，事实上，任何合法的 C 程序都是合法的 C++ 程序。

**注意：**使用静态类型的编程语言是在编译时执行类型检查，而不是在运行时执行类型检查。

## Hello World

```c++
//导入库里面头文件
#include <iostream>
//使用std的命名空间
using namespace std;
//main主函数
int main(int argc, char const *argv[])
{
    //在标准输入流输入 字符串, endl标志结尾
    cout << "hello c++" << endl;
    return 0;
}
```

c++同样要以`;`标志每行语句结束

## 注释

```c++
/* 这是注释 */
 
/* C++ 注释也可以
 * 跨行
 */

//这也是注释
```

## 数据类型

| 类型     | 关键字  |
| :------- | :------ |
| 布尔型   | bool    |
| 字符型   | char    |
| 整型     | int     |
| 浮点型   | float   |
| 双浮点型 | double  |
| 无类型   | void    |
| 宽字符型 | wchar_t |

* unsigned-无符号前缀符
* signed-有符号前缀符

## typedef

`typedef`可以给一个已有的类型声明一个新的类型

```c++
typedef type newname; 
typedef int newint;
newint a = 1;//
```

## 字符串

* c-style字符串
* string类字符串

```c++
char * str = "abcd";
char str1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

```c++
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string a = "hello string";
    std::cout << a << std::endl;

    const char * c_str = a.c_str();
    printf("c_str == %s",c_str);

    return 0;
}
```

## 枚举

枚举类型(enumeration)是C++中的一种派生数据类型，它是由用户定义的若干枚举常量的集合。

创建枚举，需要使用关键字 `enum`

```c++
enum 枚举名{ 
     标识符[=整型常数], 
     标识符[=整型常数], 
... 
    标识符[=整型常数]
} 枚举变量;
```

```c++
enum color { red, green, blue } c;
c = blue;
//red = 0
//greem = 1
```

默认情况下，第一个名称的值为 0，后续值依次`+1`

但是，也可以给名称赋予一个特殊的值，只需要添加一个初始值即可

```c++
enum color { red, green=5, blue };
//green = 5
//blue = 6
```

## 变量

```c++
int a = 1;
bool is = true;
```

### 作用域

* 局部变量：在函数或一个代码块内部声明的变量
* 全局变量：在所有函数外部声明的变量
* 形参：在函数参数的定义中声明的变量
* 实参：调用函数传入的真正的值

注意：当局部变量被定义时，系统不会对其初始化，必须自行对其初始化。

​			定义全局变量时，系统会自动初始化复制。

| 数据类型 | 初始化默认值 |
| :------- | :----------- |
| int      | 0            |
| char     | '\0'         |
| float    | 0            |
| double   | 0            |
| pointer  | NULL         |

### 常量

`常量`是固定值，在程序执行期间不会改变。所以这些固定的值，又叫做`字面量`。

### 定义常量

* 使用 `#define` 预处理器。
* 使用 `const` 关键字。

```c++
#define identifier value
#define LENGTH 10   
#define NEWLINE '\n'
```

```c++
const type variable = value;

const int  LENGTH = 10;
const char NEWLINE = '\n';
```

## 逻辑控制

```c++
if(boolean_expression)
{
   // 如果布尔表达式为真将执行的语句
}
else
{
   // 如果布尔表达式为假将执行的语句
}
```

```c++
switch(expression){
    case constant-expression  :
       statement(s);
       break; // 可选的
    case constant-expression  :
       statement(s);
       break; // 可选的
  
    // 您可以有任意数量的 case 语句
    default : // 可选的
       statement(s);
}
```

## 循环

```c++
while(condition)
{
   statement(s);
}
```

```c++
for( int a = 10; a < 20; a = a + 1 )
{
   cout << "a 的值：" << a << endl;
}
```

```c++
do
{
 cout << "a 的值：" << a << endl;
 a = a + 1;
}while( a < 20 );
```

| 控制语句                                                     | 描述                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| [break 语句](https://www.runoob.com/cplusplus/cpp-break-statement.html) | 终止 **loop** 或 **switch** 语句，程序流将继续执行紧接着 loop 或 switch 的下一条语句。 |
| [continue 语句](https://www.runoob.com/cplusplus/cpp-continue-statement.html) | 引起循环跳过主体的剩余部分，立即重新开始测试条件。           |
| [goto 语句](https://www.runoob.com/cplusplus/cpp-goto-statement.html) | 将控制转移到被标记的语句。但是不建议在程序中使用 goto 语句。 |

## 函数

`函数声明`告诉编译器函数的名称、返回类型和参数。`函数定义`提供了函数的实际主体。

`函数声明`一般放在`头文件`里面，`函数定义`实现在`cpp`中，这样编译链接后，其他文件导入`函数定义`的头文件就可以直接使用该函数。

```c++
return_type function_name( parameter list )
{
   body of the function
}
```

```c++
int max(int num1, int num2) 
{
   // 局部变量声明
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}
```

### 参数默认值

定义一个函数时可以给形参指定一个匹配类型的默认值

当调用函数时，如果实参的值留空，则使用这个默认值

```c++
int sum(int a, int b=20)
{
  int result;
 
  result = a + b;
  
  return (result);
}
```

### Lambda函数

C++11 提供了对匿名函数的支持,称为 `Lambda 函数`(也叫 `Lambda 表达式`)

Lambda 表达式把函数看作对象

```c++
//有返回值得lambda
[capture](parameters)->return-type{body}
//
[](int x, int y){ return x < y ; }
```

```c++
//无返回值的lambda
[capture](parameters){body}
//
[]{ ++global_x; } 
```

## 指针

`指针`就是存储另一个变量的`内存地址`的`变量`

```c++
type *var-name;

int    *ip;    /* 一个整型的指针 */
double *dp;    /* 一个 double 型的指针 */
float  *fp;    /* 一个浮点型的指针 */
char   *ch;    /* 一个字符型的指针 */
```

```c++
#include <iostream>
 
using namespace std;
 
int main ()
{
   int  var = 20;   // 实际变量的声明
   int  *ip;        // 指针变量的声明
 
   ip = &var;       // 在指针变量中存储 var 的地址
 
   cout << "Value of var variable: ";
   cout << var << endl;
 
   // 输出在指针变量中存储的地址
   cout << "Address stored in ip variable: ";
   cout << ip << endl;
 
   // 访问指针中地址的值
   cout << "Value of *ip variable: ";
   cout << *ip << endl;
 
   return 0;
}
```

## 引用

`引用`是一个别名，也就是说，它是某个`已存在变量`的另一个名字。

一旦把引用初始化为某个变量，就可以使用`该引用名称`或`变量名称`来指向这个变量。

### 引用和指针区别

* 不存在空引用。引用必须连接到一块合法的内存。
* 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
* 引用必须在创建时被初始化。指针可以在任何时间被初始化。

```c++
#include <iostream>
 
using namespace std;
 
int main ()
{
   // 声明简单的变量
   int    i;
   double d;
 
   // 声明引用变量
   int&    r = i;
   double& s = d;
   
   i = 5;
   cout << "Value of i : " << i << endl;
   cout << "Value of i reference : " << r  << endl;
 
   d = 11.7;
   cout << "Value of d : " << d << endl;
   cout << "Value of d reference : " << s  << endl;
   
   return 0;
}
```

`引用`通常用于`函数形参`和`函数返回值`。

## Struct-结构

和c语言的中的结构相似，但是c++中的结构可以直接在结构体中添加函数。

```c++
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book;
```

## 面向对象

### 类和对象

### 继承

### 封装

### 抽象

### 多态

### 重载

### 接口

## 异常处理

## 动态内存

## 命名空间

## 模板-泛型

## STL-标准模板库

## 参考文献

* https://www.runoob.com/cplusplus/cpp-intro.html