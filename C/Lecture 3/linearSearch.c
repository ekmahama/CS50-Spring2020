#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int array[] = {1, 9, 3, 7, 2, 19, 20, 0, 8};

    int sz = sizeof(array) / sizeof(int);

    for (int i = 0; i < sz; i++)
    {
        if (array[i] == atoi(argv[1]))
        {
            printf("Found\n");
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
