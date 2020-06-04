#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *n = get_string("Name: ");
    for (int i = 0; i < strlen(n); i++)
    {
        printf("%p\t", &n[i]);
        printf("%p\t", n + i);
        printf("%c\t", *&n[i]);
        printf("%c\n", *(n + i));
    }
    printf("%s", n);
    return 0;
}
