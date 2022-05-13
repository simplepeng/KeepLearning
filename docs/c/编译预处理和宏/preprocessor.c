#include <stdio.h>

#ifndef PI
#define PI 3.14
#endif

#define messsage_for(a, b) \
    printf(#a " and " #b ": We love you!\n")

int main(int argc, char const *argv[])
{
    printf("%f\n", PI);//3.140000

    messsage_for(hello, world);//hello and world: We love you!
    return 0;
}
