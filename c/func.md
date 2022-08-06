# 函数

- `函数(function)`是完成特定任务的独立程序代码单元。
- 函数是一组一起执行一个任务的语句。每个 C 程序都至少有一个函数，即主函数 `main()`。
- 没有返回值的函数，函数返回值类型用关键字`void`标明。
- 把函数原型和已定义的字符常量放在头文件是一个良好的编程习惯。

```c
#include <stdio.h> //导入系统的头文件
#include "custom.h" //导入自定义的头文件
```

```c
返回类型 函数名(参数列表)
{
  //一系列执行语句
}
```

```c
int max(int num1, int num2)
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

- `形式参数(形参)`是函数中存储值得变量，`实际参数(实参)`是传递给函数的特定值。
- 形参(formal argument 或 formal parameter)，实参(actual argument 或 actual parameter)

## 函数声明

```c
//sum.h
int sum(int a, int b);
```

- 函数声明(function declaration)也叫函数原型，函数原型指明了函数的属性。
- 函数声明一般定义在头文件中

## 函数实现

```c
//sum.c
#include "sum.h" //导入函数原型的头文件

int sum(int a, int b){
  return a + b;
}
```

## 递归

- C 语言允许函数调用自己，这种调用过程称为`递归(recursion)`。
- 递归函数必须有一个`终止递归的条件`，不然救护变成无限递归。
- 循环通常都可以用递归代替，递归方案更简洁，但效率大多都没循环高。

```c
int main(void)
{
  recurstion(1);
}

void recurstion(int n)
{
  if(n < 4)
  {
    recurstion(n + 1)
  }
}
```

## 尾递归

- 最简单的递归形式是把递归调用置于函数的末尾，即正好在 return 语句之前，这种形式的递归称为`尾递归(tail recustion)`，因为递归调用在函数的末尾。
- 尾递归是最简单的递归形式，因为它相当于循环。

```c
long rfact(int n)
{
  long ans;

  if(n > 0)
    ans = n * rfact(n - 1);
  else
    ans = 1;

  return ans;
}
```

- 能用循环就少用递归，但是递归更容易阅读。
- 每次递归都会创建一组变量，所以递归使用的内存更多。
- 递归每次调用都会吧创建的一组新变量放在栈中，递归调用的次数受限于内存空间。
