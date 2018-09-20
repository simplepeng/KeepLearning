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
