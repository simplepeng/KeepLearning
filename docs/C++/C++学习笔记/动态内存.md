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