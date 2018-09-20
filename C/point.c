#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    
    int a = 10;
    int *p = &a;
    printf("%d\n", *p);//10
    printf("%p\n", p);//0x7ffeee10da0c
    printf("%p\n",&p);//0x7ffeee10da00

    return 0;
}
