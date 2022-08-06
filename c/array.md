# 数组

* `数组(array)`是一种数据结构，可以存储一个固定大小的相同类型元素的顺序集合。
* 数组都是由连续的内存位置组成。最低的地址对应第一个元素，最高的地址对应最后一个元素。
* 用于识别数组元素的数字被称为`下标(subscript)`，`索引(indice)`或`偏移量(offset)`。
* 通过整数下标访问数组中单独的项或元素(element)，下标从`0`开始。

## 声明数组

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

## 数组元素个数

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

## 只读数组

* 有时需要把数组设置成只读，这样，程序只能在数组中检索元素，不能将新值写入数组。
* 要创建只读数组，应该使用`const`声明和初始化数组。

```c
const int days[] = {1,2,3,4,5,6,7};
```

## 指定初始化器(C99)

* C99增加了一个新特性：指定初始化器(designnated initializer)，利用该特性可以初始化指定的数组元素。

```c
int arr[3] = {1,2,3}; //传统的语句
int arr[3] = {[2] = 3} //把arr[2]初始化为3
```

在初始化一个元素后，未初始化的元素都会被设置为0。

## 多维数组

```c
const int days[12][31] = 
{
    {1,2,3,...,31},
    {1,2,3,4,...,28}
    ....
}
```

## 指针和数组

* 数组名是数组元素的地址。例如`arr = &arr[0]`。
* 在C语言中，`arr[i]`和`*(arr+i)`这两个表达式是等价的。