#include <stdio.h>

enum Color
{
    red = 10,
    blue = 22
};

int main(int argc, char const *argv[])
{
    enum Color color;
    color = red;
    printf("corlor == %d\n", color); //corlor == 10
    color = blue;
    printf("corlor == %d\n", color); //corlor == 22
    return 0;
}
