#include <stdio.h>

struct Person
{
    char *name;
};

typedef struct
{
    char *name;
} Person1;

int main(int argc, char const *argv[])
{
    struct Person person;
    person.name = "zhang san";
    printf("%s\n", person.name); //zhang san

    Person1 person1;
    person1.name = "li si";
    printf("%s\n", person1.name); //li si
    return 0;
}
