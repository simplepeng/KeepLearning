#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0;
    printf("a == %d\n", ++a); //a == 1
    printf("a == %d\n", ++a); //a == 2

    int b = 0;
    printf("b == %d\n", ++b); //b == 1
    printf("b == %d\n", ++b); //b == 2
    return 0;
}
