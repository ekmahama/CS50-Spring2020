#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>

void draw(int h);

int main(int argc, char const *argv[])
{
    int height = get_int("Height: ");

    draw(height);
    return 0;
}

void draw(int h)
{
    if (h == 0)
    {
        return;
    }

    draw(h - 1);

    for (int i = 0; i < h; i++)
    {
        printf("#");
    }
    printf("\n");
    
}
