#include <stdio.h>

struct Person
{
    int age;
};

typedef struct Person1
{
    int age;
} Person1;

void addAge(Person1 *person)
{
    (*person).age = 26;
    printf("%d\n", (*person).age);
    person->age = 27;
    printf("%d\n", person->age);
}

int main(int argc, char const *argv[])
{

    struct Person person;
    //Person person; #编译报错，must use 'struct' tag to refer to type 'Person'
    person.age = 25;
    printf("%d\n", person.age);

    Person1 person1;
    person1.age = 24;
    printf("%d\n", person1.age);

    addAge(&person1);

    return 0;
}
