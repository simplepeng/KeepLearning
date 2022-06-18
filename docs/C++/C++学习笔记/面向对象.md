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