#include <stdio.h>

typedef struct _Person
{
    char *name;
} Person;

int main(int argc, char const *argv[])
{
    Person *p;
    Person person;
    person.name = "zhang san";
    printf("%s\n", person.name);
    p = &person;
    //两种方式访问结构指针的值
    p->name = "li si";
    printf("%s\n", (*p).name);
    return 0;
}
