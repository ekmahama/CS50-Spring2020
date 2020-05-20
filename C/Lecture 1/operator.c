#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    int a = 5;
    int b = 2;

    printf("%i + %i: %i\n", a, b, (a + b));
    printf("%i - %i: %i\n", a, b, (a - b));
    printf("%i * %i: %i\n", a, b, (a * b));
    printf("%i mod %i: %i\n", a, b, (a % b));
    printf("%i / %i: %i\n", a, b, (a / b));
    printf("%i / %i: %.2f\n", a, b, ((float)a / b));
    printf("%i ^ %i: %f\n", a, b, pow(a, b));

    return 0;
}