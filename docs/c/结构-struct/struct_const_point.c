#include <stdio.h>

int main(int argc, char const *argv[])
{
    const int *p;
    int a = 10;
    p = &a;
    printf("%d\n", *p);

    //*p = 11;//编译报错 error: read-only variable is not assignable
    int b = 12;
    p = &b;
    printf("%d\n", *p);

    return 0;
}
