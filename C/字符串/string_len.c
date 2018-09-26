#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char hello[] = "hello";
    printf("%s\n", hello);//hello

    printf("str len == %lu\n",strlen(hello));//str len == 5

    int realLen = sizeof(hello) / sizeof(char);
    printf("realLen == %d\n",realLen);//realLen == 6
    return 0;
}
