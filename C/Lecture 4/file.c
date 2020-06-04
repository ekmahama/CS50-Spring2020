#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *file = fopen("phonebook.csv", "a");
    fprintf(file, "Name\tNumber\n");
    for (int i = 0; i < 5; i++)
    {
        char *name = get_string("Name: ");
        int number = get_int("Number: ");
        fprintf(file, "%s\t%i\n", name, number);
    }

    fclose(file);
    return 0;
}
