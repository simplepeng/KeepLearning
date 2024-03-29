# 结构体

```c
struct Preson{
    char* name;
    int age;
};

int main()
{
    struct Person person;
    person.age = 25;
    printf("%d\n", person.age);//25
}
```

* 结构体括号结尾要带上分号`;`

## typedef简写结构体

```c
typedef struct
{
    char* name;
    int age;
} Person;

//或
typedef struct _Person
{
    char* name;
    int age;
} Person;

int main()
{
    Person person;
    person.age = 25;
    printf("%d\n", person.age);//25
}
```

## 结构体指针

```c
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
```

结构体作为函数参数

1. 直接传递结构体给函数

```c
typedef struct _Person
{
    char *name;
} Person;

void fun1(Person person);

int main(int argc, char const *argv[])
{
    Person p;
    p.name = "zhang san";
    printf("start -- %s\n", p.name);
    fun1(p);
    printf("end --%s\n", p.name);
    return 0;
}

void fun1(Person p)
{
    p.name = "li si";
}
```

> start -- zhang san
> end --zhang san

2. 传递结构体指针给函数

```c
#include <stdio.h>

typedef struct _Person
{
    char *name;
} Person;

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

void fun2(Person *p)
{
    p->name = "li si";
}
```

> start -- zhang san
> end --li si

## 结构体长度

结构体的长度一般为结构中字段长度的总和。

```c
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
```

## const的结构指针

const后的指针不能修改所指向地址的值，结构指针也是一样。但是可以重新指向其他的地址。

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    const int *p;
    int a = 10;
    p = &a;
    printf("%d\n", *p);//10

    *p = 11;//编译报错 error: read-only variable is not assignable

    int b = 12;
    p = &b;
    printf("%d\n", *p);//12
    
    return 0;
}
```

## 结构体增加函数

```c
#include <stdio.h>

typedef struct
{
    void (*eat)();
} Person;

void eat()
{
    printf("%s\n", "每次多吃一粒米");
}

int main(int argc, char const *argv[])
{
    Person p;
    p.eat = &eat;
    p.eat();
    
    //指针方式
    // Person *p1;
    // p1 = &p;
    // p1->eat = &eat;
    // p1->eat();
    return 0;
}
```