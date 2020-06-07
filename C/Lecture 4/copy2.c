#include <stdio.h>
#include <cs50.h>

void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    printf("Before Swap: x = %i and y = %i\n", x, y);
    swap(&x, &y);
    printf("After Swap: x = %i and y = %i\n", x, y);

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
