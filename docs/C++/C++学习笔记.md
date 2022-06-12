## 简介

C++ 是一种静态类型的、编译式的、通用的、大小写敏感的、不规则的编程语言，支持过程化编程、面向对象编程和泛型编程。

C++ 被认为是一种中级语言，它综合了高级语言和低级语言的特点。

C++ 是由 Bjarne Stroustrup 于 1979 年在新泽西州美利山贝尔实验室开始设计开发的。C++ 进一步扩充和完善了 C 语言，最初命名为带类的C，后来在 1983 年更名为 C++。

C++ 是 C 的一个超集，事实上，任何合法的 C 程序都是合法的 C++ 程序。

注意：使用静态类型的编程语言是在编译时执行类型检查，而不是在运行时执行类型检查。

## HelloWorld

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

## 类型别名(typedef)

`typedef`可以给一个已有的类型声明一个新的类型

```c++
typedef type newname; 
typedef int newint;
newint a = 1;
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

* 局部变量：在函数或一个代码块内部声明的变量
* 全局变量：在所有函数外部声明的变量
* 形参：在函数参数的定义中声明的变量
* 实参：调用函数传入的真正的值

当局部变量被定义时，系统不会对其初始化，必须自行对其初始化。

定义全局变量时，系统会自动初始化复制。

| 数据类型 | 初始化默认值 |
| :------- | :----------- |
| int      | 0            |
| char     | '\0'         |
| float    | 0            |
| double   | 0            |
| pointer  | NULL         |

## 常量

`常量`是固定值，在程序执行期间不会改变。所以这些固定的值，又叫做`字面量`。

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

## 遍历

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
| break 语句 | 终止 **loop** 或 **switch** 语句，程序流将继续执行紧接着 loop 或 switch 的下一条语句。 |
| continue 语句 | 引起循环跳过主体的剩余部分，立即重新开始测试条件。           |
| goto 语句 | 将控制转移到被标记的语句。但是不建议在程序中使用 goto 语句。 |

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

* 参数默认值

定义一个函数时可以给形参指定一个匹配类型的默认值

当调用函数时，如果实参的值留空，则使用这个默认值

```c++
int sum(int a, int b = 20)
{
  int result;
 
  result = a + b;
  
  return (result);
}
```

* Lambda函数

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

## 引用和指针区别

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

## 结构体

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

## 类和对象

类的定义以`class`关键字开头，然后是类的名称。

类的主体是包含在一对花括号中。

类定义后必须跟着一个分号或一个声明列表。

```c++
class Box
{
   public:
      double length;   // 盒子的长度
      double breadth;  // 盒子的宽度
      double height;   // 盒子的高度
};
```

`public`是类的访问权限修饰符，还有`private`，`protected`

```c++
int main( )
{
   Box Box1;        // 声明 Box1，类型为 Box
   Box Box2;        // 声明 Box2，类型为 Box
   double volume = 0.0;     // 用于存储体积
  
  // box 1 详述
   Box1.height = 5.0; 
   Box1.length = 6.0; 
   Box1.breadth = 7.0;
}
```

类的对象的`公共数据成员`可以使用直接`成员访问运算符 (.)` 来访问

## 构造和析构函数

`构造函数`和`析构函数`都不能被继承，基类的构造函数需要派生类手动调用。

在派生类的析构函数不用显示调用基类的析构函数，因为每个类只有一个析构函数。

```c++
#include <iostream>

using namespace std;

class A{
public:
    A(){cout<<"A constructor"<<endl;}
    ~A(){cout<<"A destructor"<<endl;}
};

class B: public A{
public:
    B(){cout<<"B constructor"<<endl;}
    ~B(){cout<<"B destructor"<<endl;}
};
```

构造函数和析构函数执行顺序相反。基类的构造函数会先被调用，然后调用子类的构造函数，而析构函数恰恰相反，子类的析构函数会先被调用，然后再是基类的析构函数。

```c++
#include<iostream>
using namespace std;
//基类People
class People{
protected:
    char *m_name;
    int m_age;
public:
    People(char*, int);
};
People::People(char *name, int age): m_name(name), m_age(age){
  
}

//派生类Student
class Student: public People{
private:
    float m_score;
public:
    Student(char *name, int age, float score);
    void display();
};
//People(name, age)就是调用基类的构造函数
Student::Student(char *name, int age, float score): People(name, age), m_score(score){
  
}
void Student::display(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<"。"<<endl;
}

int main(){
    Student stu("小明", 16, 90.5);
    stu.display();
    return 0;
}
```

## 继承

创建一个新类去继承一个已有的类，可以达到重用代码功能和提高执行效率的效果。

这个已有的类为`基类或父类`，新建的类称为`派生类或子类`

```c++
// 基类
class Shape 
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};

// 派生类
class Rectangle: public Shape
{
   public:
      int getArea()
      { 
         return (width * height); 
      }
};

int main(void)
{
   Rectangle Rect;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
 
   // 输出对象的面积
   cout << "Total area: " << Rect.getArea() << endl;
 
   return 0;
}
```

## 多继承

c++允许子类多继承，也就是子类可以继承多个父类。每个父类间用`,`分隔

```c++
// 派生类
class Rectangle: public Shape, public PaintCost
{
   public:
      int getArea()
      { 
         return (width * height); 
      }
};
```

## 继承的访问控制


| 访问     | public | protected | private |
| :------- | :----- | :-------- | :------ |
| 同一个类 | yes    | yes       | yes     |
| 派生类   | yes    | yes       | no      |
| 外部的类 | yes    | no        | no      |

## 封装

`封装`也叫`数据隐藏`是面向对象编程中一个重要的概念。

类包含`私有成员（private`）、`保护成员（protected)`和`公有成员（public）`成员。

```c++
class Box
{
   public://公有
      double getVolume(void)
      {
         return length * breadth * height;
      }
   private://私有
      double length;      // 长度
      double breadth;     // 宽度
      double height;      // 高度
};
```

## 多态

`多态（polymorphism`指的是同一名字的事物可以完成不同的功能。

多态可以分为`编译时的多态`和`运行时的多态`。

函数的重载（包括运算符的重载）、对重载函数的调用，在编译时就能根据实参确定应该调用哪个函数，因此叫`编译时的多态`

继承、虚函数等指`运行时的多态`

多态是面向对象编程的主要特征之一，C++中`虚函数`的唯一用处就是构成多态。

## 重载

重载分为`函数重载`和`运算符重载`

`重载函数`：在同一作用域下，可以声明同名的函数，但是函数的形参必须不一样(个数，类型或顺序)，不能仅通过返回类型定义重载函数。

```c++
#include <iostream>
using namespace std;
 
class printData
{
   public:
      void print(int i) {
        cout << "整数为: " << i << endl;
      }
 
      void print(double  f) {
        cout << "浮点数为: " << f << endl;
      }
 
      void print(char c[]) {
        cout << "字符串为: " << c << endl;
      }
};
```

 注：上面类其实会生成相应类型的函数，列入：print_int，print_double...

`重载运算符`：重载的运算符是带有特殊名称的函数，函数名是由关键字 `operator `和其后要`重载的运算符符号`构成的。与其他函数一样，重载运算符有一个返回类型和一个参数列表。

```c++
//声明加法运算符用于把两个 Box 对象相加，返回最终的 Box 对象。
Box operator+(const Box&);
```

```c++
#include <iostream>
using namespace std;
 
class Box
{
   public:
 
      double getVolume(void)
      {
         return length * breadth * height;
      }
      void setLength( double len )
      {
          length = len;
      }
 
      void setBreadth( double bre )
      {
          breadth = bre;
      }
 
      void setHeight( double hei )
      {
          height = hei;
      }
      // 重载 + 运算符，用于把两个 Box 对象相加
      Box operator+(const Box& b)
      {
         Box box;
        //对象的属性使用 this 运算符进行访问
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }
   private:
      double length;      // 长度
      double breadth;     // 宽度
      double height;      // 高度
};

int main( )
{
 Box Box1;                // 声明 Box1，类型为 Box
   Box Box2;                // 声明 Box2，类型为 Box
   Box Box3;                // 声明 Box3，类型为 Box
   double volume = 0.0;     // 把体积存储在该变量中
 
   // Box1 详述
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);
 
   // Box2 详述
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);
  
  // 把两个对象相加，得到 Box3
   Box3 = Box1 + Box2;
 
   // Box3 的体积
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;
 
   return 0;
}
```

## 虚函数

使用虚函数非常简单，只需要在函数声明前面增加 `virtual` 关键字。

```c++
#include <iostream>

using namespace std;

//基类People
class People{
public:
    People(char *name, int age);
    virtual void display();  //声明为虚函数
protected:
    char *m_name;
    int m_age;
};
People::People(char *name, int age): m_name(name), m_age(age){}
void People::display(){
    cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;
}

//派生类Teacher
class Teacher: public People{
public:
    Teacher(char *name, int age, int salary);
    virtual void display();  //声明为虚函数
private:
    int m_salary;
};
Teacher::Teacher(char *name, int age, int salary): People(name, age), m_salary(salary){}
void Teacher::display(){
    cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;
}

int main(){
    People *p = new People("王志刚", 23);
    p -> display();
    p = new Teacher("赵宏佳", 45, 8200);
    p -> display();
    return 0;
}

//王志刚今年23岁了，是个无业游民。
//赵宏佳今年45岁了，是一名教师，每月有8200元的收入。
```

## 抽象

包含`纯虚函数`的类称为`抽象类（Abstract Class）`

在`虚函数`声明的结尾加上`=0`，表明此函数为`纯虚函数`。

```c++
virtual 返回值类型 函数名 (函数参数) = 0;
```

抽象类通常是作为基类，让派生类去实现纯虚函数。派生类必须实现纯虚函数才能被实例化。

```c++
#include <iostream>
using namespace std;

//线
class Line{
public:
    Line(float len);
    virtual float area() = 0;
    virtual float volume() = 0;
protected:
    float m_len;
};
Line::Line(float len): m_len(len){ }

//矩形
class Rec: public Line{
public:
    Rec(float len, float width);
    float area();
protected:
    float m_width;
};
Rec::Rec(float len, float width): Line(len), m_width(width){ }
float Rec::area(){ return m_len * m_width; }

//长方体
class Cuboid: public Rec{
public:
    Cuboid(float len, float width, float height);
    float area();
    float volume();
protected:
    float m_height;
};
Cuboid::Cuboid(float len, float width, float height): Rec(len, width), m_height(height){ }
float Cuboid::area(){ return 2 * ( m_len*m_width + m_len*m_height + m_width*m_height); }
float Cuboid::volume(){ return m_len * m_width * m_height; }

//正方体
class Cube: public Cuboid{
public:
    Cube(float len);
    float area();
    float volume();
};
Cube::Cube(float len): Cuboid(len, len, len){ }
float Cube::area(){ return 6 * m_len * m_len; }
float Cube::volume(){ return m_len * m_len * m_len; }

int main(){
    Line *p = new Cuboid(10, 20, 30);
    cout<<"The area of Cuboid is "<<p->area()<<endl;
    cout<<"The volume of Cuboid is "<<p->volume()<<endl;
  
    p = new Cube(15);
    cout<<"The area of Cube is "<<p->area()<<endl;
    cout<<"The volume of Cube is "<<p->volume()<<endl;
    return 0;
}
```

## 异常处理

c++异常处理主要使用三个关键字`try`，`catch`和`throw`

```c++
try
{
   // 保护代码
}catch( ExceptionName e1 )
{
   // catch 块
}catch( ExceptionName e2 )
{
   // catch 块
}catch( ExceptionName eN )
{
   // catch 块
}
```

## 定义新的异常

通过继承`std::exception`来新建异常类，通过重写`what`函数来返回异常原因。

```c++
#include <iostream>
#include <exception>

using namespace std;

class CustomException : public exception
{
    public:
    const char *what() const throw()
    {
        return "This is CustomException";
    }
};

int main(int argc, char const *argv[])
{
    try
    {
        throw CustomException();
    }
    catch (CustomException &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
```

## 动态内存

C++ 程序中的内存分为两个部分：

* `栈`：在函数内部声明的所有变量都将占用栈内存
* `堆`：在程序运行时可动态申请的内存空间

在c++中使用`new`关键字动态分配内存，使用`delete`关键字删除之前分配的内存，这两个关键字一般都是`成对出现`的。

```c++
#include <iostream>
using namespace std;
 
int main ()
{
   double* pvalue  = NULL; // 初始化为 null 的指针
   pvalue  = new double;   // 为变量请求内存
 
   *pvalue = 29494.99;     // 在分配的地址存储值
   cout << "Value of pvalue : " << *pvalue << endl;
 
   delete pvalue;         // 释放内存
 
   return 0;
}
```

数组的动态内存分配

```c++
char* pvalue  = NULL;   // 初始化为 null 的指针
pvalue  = new char[20]; // 为变量请求内存

delete [] pvalue;        // 删除 pvalue 所指向的数组
```

c语言中的`malloc`函数在c++依然适用，但是在c++中还是使用c++的特性比较好，就像能用`class`的地方就最好不用`struct`。

## 命名空间

命名空间使用`namespace`关键字定义

```c++
namespace namespace_name {
   // 代码声明
}

name::code;  // code 可以是变量或函数
//
std::cout;
std::endl;
```

可以使用`using`指令告诉后续代码使用指定的命名空间，简化调用

```c++
#include <iostream>

using namespace std; 
// 第一个命名空间
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
}
// 第二个命名空间
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}
//使用第一个命名空间
using namespace first_space;

int main ()
{
 
   // 调用第一个命名空间中的函数
   func();
   
   return 0;
}
```

命名空间可以定义在几个不同的部分中，下面的命名空间定义可以是定义一个新的命名空间，也可以是为已有的命名空间增加新的元素：

```c++
namespace namespace_name {
   // 代码声明
}
```

命名空间可以嵌套，可以在一个命名空间中定义另一个命名空间

```c++
namespace namespace_name1 {
   // 代码声明
   namespace namespace_name2 {
      // 代码声明
   }
}
```

## 模板(泛型)

模板是泛型编程的基础，我们可以使用模板来定义函数和类。所以c++中有两种模板

* `模板类`
* `模板函数`

```c++
#include <iostream>

using namespace std;

template<typename T> void Swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    //交换 int 变量的值
    int n1 = 100, n2 = 200;
    Swap(n1, n2);
    cout<<n1<<", "<<n2<<endl;
   
    //交换 float 变量的值
    float f1 = 12.5, f2 = 56.93;
    Swap(f1, f2);
    cout<<f1<<", "<<f2<<endl;
  
   return 0;
}
```

```c++
#include <iostream>
using namespace std;

template<class T1, class T2>  //这里不能有分号
class Point{
public:
    Point(T1 x, T2 y): m_x(x), m_y(y){ }
public:
    T1 getX() const;  //获取x坐标
    void setX(T1 x);  //设置x坐标
    T2 getY() const;  //获取y坐标
    void setY(T2 y);  //设置y坐标
private:
    T1 m_x;  //x坐标
    T2 m_y;  //y坐标
};

template<class T1, class T2>  //模板头
T1 Point<T1, T2>::getX() const /*函数头*/ {
    return m_x;
}

template<class T1, class T2>
void Point<T1, T2>::setX(T1 x){
    m_x = x;
}

template<class T1, class T2>
T2 Point<T1, T2>::getY() const{
    return m_y;
}

template<class T1, class T2>
void Point<T1, T2>::setY(T2 y){
    m_y = y;
}

int main(){
    Point<int, int> p1(10, 20);
    cout<<"x="<<p1.getX()<<", y="<<p1.getY()<<endl;
    Point<int, char*> p2(10, "东经180度");
    cout<<"x="<<p2.getX()<<", y="<<p2.getY()<<endl;
    Point<char*, char*> *p3 = new Point<char*, char*>("东经180度", "北纬210度");
    cout<<"x="<<p3->getX()<<", y="<<p3->getY()<<endl;
    return 0;
}
```

`typename`关键字也可以使用`class`关键字替代，它们没有任何区别。C++ 早期对模板的支持并不严谨，没有引入新的关键字，而是用 class 来指明类型参数，但是 class 关键字本来已经用在类的定义中了，这样做显得不太友好，所以后来 C++ 又引入了一个新的关键字 typename，专门用来定义类型参数。

## STL-标准模板库

C++ 的`标准模板库（Standard Template Library，STL）`是泛型程序设计最成功应用的实例。

STL 是一些常用数据结构（如链表、可变长数组、排序二叉树）和算法（如排序、查找）的模板的集合

## Reference

* https://www.runoob.com/cplusplus/cpp-intro.html
* http://c.biancheng.net/cplus/