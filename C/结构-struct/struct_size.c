#include <stdio.h>

typedef struct _Person
{
    int age;
} Person;

int main(int argc, char const *argv[])
{
    Person p;
    p.age = 18;
    printf("%lu\n", sizeof(p));
    return 0;
}
