## 指针

指针是存储其他变量`地址`的变量。

### 声明指针

```c
类型名 *指针名;
```

`星号(*)`是间接运算符(indirection operator)，表明指针名是一个指向类型名类型的指针，不是类型名类型的变量。

```c
int *a;
```

### 初始化指针

```c
指针 = &变量;
```

```c
int b = 10;
a = &b;
```

取址运算符(&)获取变量的内存地址，并将其放入指针变量中。

通过变量名访问变量的内容，称之为**直接访问(direct access)**

通过指向变量的指针访问变量的内容，称为**间接访问(indirect)**或**间接取值(indirecion)**

**指针名**输出的是指向变量的内存地址，***指针名**输出的指向变量存储的值

内存中每个字节都有唯一的地址，因此，多字节变量实际占用了多个地址，变量的地址是它占用字节的首地址（最低位的地址）

### 函数指针

函数指针是指向函数的指针变量。

```c
#include <stdio.h>

void (*add)(int, int);

void addImp(int x, int y)
{
    printf("sum == %d\n", x + y);
}

int main(int argc, char const *argv[])
{
    add = &addImp;
    add(2, 3);
    return 0;
}
```

输出：

```c
sum == 5
```

### 空指针

在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。

赋为 NULL 值的指针被称为**空**指针。

NULL 指针是一个定义在标准库中的值为零的常量。

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *pointNull = NULL;
    printf("pointNull 的地址是 %p\n", pointNull);//pointNull 的地址是 0x0
    return 0;
}
```

### void指针

void指针泛指为通用指针（generic pointer），也可以称为泛型指针，即指向任意数据对象类型的指针。

```c
void *指针名；
```

void指针最常见的用途就是声明函数的参数。如果希望一个函数能处理不同类型的参数，便可将void指针作为函数的参数。

要使用void指针必须使用**强制类型转换**

```c
(type *)指针名;
```

```c
#include <stdio.h>

void printVoid(void *value, int position)
{
    switch (position)
    {
    case 1:
        printf("value == %d\n", *((int *)value));
        break;
    case 2:
        printf("value == %ld\n", *((long *)value));
        break;
    case 3:
        printf("value == %f\n", *((float *)value));
        break;
    }
}

int main(int argc, char const *argv[])
{
    int a = 10;
    printVoid(&a, 1);
    long b = 110;
    printVoid(&b, 2);
    float c = 3.14;
    printVoid(&c, 3);
    return 0;
}
```

输出结果：

> value == 10
> value == 110
> value == 3.140000