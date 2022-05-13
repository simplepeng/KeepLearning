#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 8;
    a = a << 1;        //8*2的一次方
    printf("%d\n", a); //16
    a = a << 2;        //8*2的二次方
    printf("%d\n", a); //32

    int b = 8;
    b = b >> 1;        //8 / 2的一次方
    printf("%d\n", b); //4
    b = b >> 2;        //8 / 2的一次方
    printf("%d\n", b); //1
    return 0;
}
