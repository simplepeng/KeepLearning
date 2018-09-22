#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a = 100;
    const int *p = &a;
    printf("a == %d\n", a);   //100
    printf("*p == %d\n", *p); //100
    printf("p == %p\n", p);   //0x7ffee21c4a0c
    //*p = 111; // error:read-only variable is not assignable
    //printf("a == %d\n",a);
    int b = 111;
    p = &b;
    printf("*p == %d\n", *p); //111
    printf("p == %p\n", p);   //0x7ffee8b149fc

    int c = 222;
    int *const p1 = &c;
    printf("c == %d\n", c);     //222
    printf("*p1 == %d\n", *p1); //222
    printf("p1 == %p\n", p1);   //0x7ffee1d729f8
    *p1 = 333;                  //ok
    printf("*p1 == %d\n", *p1); //333
    int d = 444;
    p1 = &d;//error: cannot assign to variable 'p1' with const-qualified type 'int *const'

    return 0;
}
