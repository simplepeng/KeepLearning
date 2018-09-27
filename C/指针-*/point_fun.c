#include <stdio.h>

void (*add)(int, int);

void addImp(int x, int y)
{
    printf("sum == %d\n", x + y);
}

int main(int argc, char const *argv[])
{
    add = &addImp;
    add(2, 3);
    return 0;
}
