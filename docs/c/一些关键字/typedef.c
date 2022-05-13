#include <stdio.h>

typedef char* string;
typedef unsigned int Integer;

int main(int argc, char const *argv[])
{
    string a = "hello";
    printf("%s\n", a); //hello
    Integer b = 100;
    printf("%d\n", b);//100
    return 0;
}
