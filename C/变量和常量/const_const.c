#include <stdio.h>

const double PI = 3.14;

int main(int argc, char const *argv[])
{
    printf("PI == %f\n",PI);  
    //PI = 3.15;  error: cannot assign to variable 'PI' with const-qualified type 'const double'
    return 0;
}
