#include <stdio.h>

union Color {
    int red;
    long double yellow;
};

int main(int argc, char const *argv[])
{
    union Color color;
    color.red = 1;
    printf("%d\n", color.red);
    return 0;
}
