# 函数

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

* `形式参数(形参)`是函数中存储值得变量，`实际参数(实参)`是传递给函数的特定值。

## 函数声明

```c
//sum.h
int sum(int a, int b);
```

* 函数声明(function declaration)也叫函数原型，函数原型指明了函数的属性。
* 函数声明一般定义在头文件中

## 函数实现

```c
//sum.c
#include "sum.h" //导入函数原型的头文件

int sum(int a, int b){
  return a + b;
}
```