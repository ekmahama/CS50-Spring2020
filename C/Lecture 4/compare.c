#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool compareInt(int a, int b);
bool compareStr(char *s, char *t);

int main(int argc, char const *argv[])
{
    int a = 2;
    int b = 3;

    char *s = "Kofi";
    char *t = "John";
    printf("%i\n", compareInt(a, b));
    printf("%i\n", compareStr(s, t));
    return 0;
}

bool compareInt(int a, int b)
{
    return a == b;
}

bool compareStr(char *s, char *t)
{
    return !strcmp(s, t);
}