#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *t = malloc(10 * sizeof(int));
    t[1] = 10;

    printf("%i\n", t[3]);

    free(t);
    return 0;
}
