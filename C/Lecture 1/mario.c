#include <cs50.h>
#include "stdio.h"
void printHashes(int n);
/*
My implementation of supermario
*/

int main(void)
{
    int n;
    do
    {
        n = get_int("height: ");
    } while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int m = 1; m < n - i; m++)
        {
            printf(" ");
        }
        printHashes(i);
        printf("  "); // print double space
        printHashes(i);
        printf("\n"); // Print newline
    }
}

void printHashes(int n)
{
    for (int j = 0; j <= n; j++)
    {
        printf("#");
    }
}
