#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = (5 == 5);
    printf("a == %d\n", a);//a == 1
    int b = (5 == 1);
    printf("b == %d\n", b);//b == 0
    return 0;
}
