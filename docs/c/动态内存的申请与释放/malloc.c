#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *hello;
    //strcpy(hello, "hello world"); //运行报错 segmentation fault
    hello = (char*)malloc(strlen("helloworld") * sizeof(char));
    strcpy(hello, "hello world");
    printf("%s\n", hello);
    return 0;
}
