#include <stdio.h>

enum Color
{
    red,
    blue
};

int main(int argc, char const *argv[])
{
    enum Color color;
    color = red;
    printf("corlor == %d\n", color);//corlor == 0
    color = blue;
    printf("corlor == %d\n", color);//corlor == 1
    return 0;
}
