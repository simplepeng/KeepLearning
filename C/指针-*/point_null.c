#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *pointNull = NULL;
    printf("pointNull 的地址是 %p\n", pointNull);//pointNull 的地址是 0x0
    return 0;
}
