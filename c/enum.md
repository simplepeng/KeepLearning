# 枚举

枚举是 C 语言中的一种基本数据类型，它可以让数据更简洁，更易读。

## 定义枚举

```c
enum 枚举名
{
    枚举元素,
    枚举元素,
    枚举元素,
    ...
}
```

第一个枚举成员的默认值为整型的 0，后续枚举成员的值在前一个成员上加 1。

```c
#include <stdio.h>

enum Color
{
    red,
    blue
};

int main(int argc, char const *argv[])
{
    enum Color color;
    color = red;
    printf("corlor == %d\n", color);//corlor == 0
    color = blue;
    printf("corlor == %d\n", color);//corlor == 1
    return 0;
}
```

在C 语言中，枚举类型是被当做 int 或者 unsigned int 类型来处理的。

## 自定义枚举元素的值

```c
#include <stdio.h>

enum Color
{
    red = 10,
    blue = 22
};

int main(int argc, char const *argv[])
{
    enum Color color;
    color = red;
    printf("corlor == %d\n", color); //corlor == 10
    color = blue;
    printf("corlor == %d\n", color); //corlor == 22
    return 0;
}
```