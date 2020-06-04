#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./fread image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("Malloc error\n");
        return 2;
    }

    unsigned char bytes[3];

    // Read 3 bytes from file into bytes just once
    fread(bytes, 3, 1, file);

    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("May be JPEG\n");
    }
    else
    {
        printf("Not JPEG\n");
    }

    fclose(file);
    return 0;
}
