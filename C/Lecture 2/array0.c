#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // Chars can store ints
    unsigned char numbers[] = {2, 3, 4, 5};

    int scores[4] = {95, 97, 96, 98};

    char *names[] = {"Edward", "Mavis", "Kofi", "Lark"};

    // A string is an array of chars
    string s = get_string("Input: ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
    printf("%s\n", s);

    // for (int i = 0; i < 4; i++)
    // {
    //     printf("i = %i\n", numbers[i]);
    //     printf("score %i : %i\n", i, scores[i]);
    //     printf("Name %i : %s\n", i, names[i]);
    // }

    return 0;
}
