#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 1;
    a++;
    printf("a == %d\n", a); //a == 2
    a++;
    printf("a == %d\n", a); //a == 3

    int b = 10;
    b--;
    printf("b == %d\n", b); //b == 9
    b--;
    printf("b == %d\n", b); //b == 8
    return 0;
}
