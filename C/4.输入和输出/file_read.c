#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    //打开文件
    file = fopen("hello.txt", "r");
    //读取文件
    int result = fgetc(file);
    if (result != EOF)
    {
        printf("读取字符成功 result == %d\n", result);
    }
    char buffer[255];
    fgets(buffer, 255, (FILE*)file);
    printf("rc == %s\n", buffer);
    //关闭文件
    fclose(file);
    return 0;
}
