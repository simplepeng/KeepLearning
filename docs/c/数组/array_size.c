#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    printf("arr size == %d\n", size);
    return 0;
}
