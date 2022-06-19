## 字符串

在 C 语言中，字符串实际上是使用 **null** 字符 **'\0'** 终止的一维字符数组。

```c
char hello[6] = {'h','e','l','l','o','\0'};
```

其实，不需要把`null`字符放在字符串常量的末尾。C 编译器会在初始化数组时，自动把 '\0' 放在字符串的末尾。

```c
char hello[] = "hello";
```

还可以使用指针来初始化字符串

```c
char *hello = "hello";
```

C语言中有大量操作字符串的函数，都放在**string.h**头文件中

| 函数                | 描述                                                         |
| :------------------ | ------------------------------------------------------------ |
| **strcpy(s1, s2);** | 复制字符串 s2 到字符串 s1                                    |
| **strcat(s1, s2);** | 连接字符串 s2 到字符串 s1 的末尾                             |
| **strlen(s1);**     | 返回字符串 s1 的长度                                         |
| **strcmp(s1, s2);** | 如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0 |
| **strchr(s1, ch);** | 返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置     |
| **strstr(s1, s2);** | 返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置   |

```c
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str1[12] = "hello";
    char str2[12] = "world";

    //复制字符串
    char str3[12];
    strcpy(str3, str1);
    printf("%s\n", str3); //hello
    //连接字符串
    strcat(str1, str2);
    printf("%s\n", str1); //helloworld
    return 0;
}
```

```c
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char hello[] = "hello";
    printf("%s\n", hello);//hello

    printf("str len == %lu\n",strlen(hello));//str len == 5

    int realLen = sizeof(hello) / sizeof(char);
    printf("realLen == %d\n",realLen);//realLen == 6
    return 0;
}
```

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *str = "hello";
    printf("str == %s\n", str);//hello

    //用指针表示的字符串不能修改，但是用字符数组的可以修改
    //str[0] = 'w';//bus error
    //printf("str == %s\n", str);
    char strArr[] = "hello";
    strArr[0] = 'w';
    printf("&strArr == %s\n",strArr);//wello

    char *str1 = "hello";
    printf("&str == %p\n",&str);//0x7ffee88f4a08
    printf("&str1 == %p\n",&str1);//0x7ffee88f4a00
    return 0;
}
```