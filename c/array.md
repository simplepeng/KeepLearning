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