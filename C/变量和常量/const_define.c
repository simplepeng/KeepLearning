#include <stdio.h>

#define PI 3.14

int main(int argc, char const *argv[])
{
    printf("PI == %f\n", PI);
    //PI = 3.15; error: expression is not assignable
    return 0;
}
