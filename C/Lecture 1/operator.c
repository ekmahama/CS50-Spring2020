#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    int a = 5;
    int b = 2;
    int x = 5;

    // Arithmetic Operators
    x += 5; // x = x + 5;
    x *= 5; // x = x * 5;
    x /= 2; // x = x/2
    x %= 2; // x = x%2
    x--;    // x =x-1
    x++;    // x = x+1

    printf("%i + %i: %i\n", a, b, (a + b));
    printf("%i - %i: %i\n", a, b, (a - b));
    printf("%i * %i: %i\n", a, b, (a * b));
    printf("%i mod %i: %i\n", a, b, (a % b));
    printf("%i / %i: %i\n", a, b, (a / b));
    printf("%i / %i: %.2f\n", a, b, ((float)a / b));
    printf("%i ^ %i: %f\n", a, b, pow(a, b));


    // Logical Operators
    

    return 0;
}