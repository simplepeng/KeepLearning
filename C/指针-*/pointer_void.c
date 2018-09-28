#include <stdio.h>

void printVoid(void *value, int position)
{
    switch (position)
    {
    case 1:
        printf("value == %d\n", *((int *)value));
        break;
    case 2:
        printf("value == %ld\n", *((long *)value));
        break;
    case 3:
        printf("value == %f\n", *((float *)value));
        break;
    }
}

int main(int argc, char const *argv[])
{
    int a = 10;
    printVoid(&a, 1);
    long b = 110;
    printVoid(&b, 2);
    float c = 3.14;
    printVoid(&c, 3);
    return 0;
}
