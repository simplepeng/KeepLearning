#include <stdio.h>

typedef struct
{
    void (*eat)();
} Person;

void eat()
{
    printf("%s\n", "每次多吃一粒米");
}

void fun1(Person *p)
{
    p->eat();
}

int main(int argc, char const *argv[])
{
    Person p;
    // p.eat = &eat;
    // p.eat();

    Person *p1;
    p1 = &p;
    p1->eat = &eat;
    // p1->eat();

    fun1(p1);
    return 0;
}
