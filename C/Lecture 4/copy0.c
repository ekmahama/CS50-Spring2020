#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *s = "Edward";
    char *t = malloc(strlen(s) + 1);

    strcpy(t, s);

    printf("%s\n", s);
    printf("%s\n", t);

    free(t);
    return 0;
}
