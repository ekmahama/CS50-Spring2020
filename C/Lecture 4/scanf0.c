#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int x;
    printf("x: ");
    scanf("%i", &x);

    char *s = malloc(sizeof(char) * 5);
    printf("Name: ");
    scanf("%s", s);

    printf("Name: %s\n", s);
    printf("x = %i\n", x);

    free(s);
    return 0;
}
