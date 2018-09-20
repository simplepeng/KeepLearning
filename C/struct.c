#include <stdio.h>

struct Person
{
    int age;
};

int main(int argc, char const *argv[])
{

    struct Person person;
    person.age = 25;

    printf("%d\n", person.age);
    return 0;
}
