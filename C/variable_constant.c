#include <stdio.h>

//常量
#define PI 3.14
int main()
{
    //变量
    int a = 10;
    printf("a == %d\n", a);//a = 10
    a = 11;
    printf("a == %d\n", a);//a = 11

   
    const int b = 10;
    printf("b == %d\n", b);//b = 10
    //b = 11;
    //printf("b == %d\n", b);//编译报错，variable 'b' declared const here

    return 0;
}