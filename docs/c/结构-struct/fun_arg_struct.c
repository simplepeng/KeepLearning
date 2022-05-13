#include <stdio.h>

typedef struct _Person
{
    char *name;
} Person;

void fun1(Person person);
void fun2(Person *person);

int main(int argc, char const *argv[])
{
    Person p;
    p.name = "zhang san";
    printf("start -- %s\n", p.name);
    fun2(&p);
    printf("end --%s\n", p.name);
    return 0;
}

void fun1(Person p)
{
    p.name = "li si";
}

void fun2(Person *p)
{
    p->name = "li si";
}
