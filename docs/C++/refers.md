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