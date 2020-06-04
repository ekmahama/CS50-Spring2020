#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *s = "Edward";
    printf("%s\n", s);
    printf("%s\n", &s[0]);
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    return 0;
}
