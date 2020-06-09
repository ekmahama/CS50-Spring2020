#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

void print_usage();
bool foundJPEGheader(BYTE *buffer);
int main(int argc, char *argv[])
{
    // Check if appropriate argument is given
    if (argc != 2)
    {
        print_usage();
        return 1;
    }

    // Open forensic file for reading
    FILE *inputPtr = fopen(argv[1], "r");

    // Check if file was successfuly opened
    if (!inputPtr)
    {
        printf("%s cannot be opened\n", argv[1]);
        return 1;
    }

    // Look for JPEG header
    BYTE *buffer = malloc(512);
    int fileNum = 0;
    char filename[8];
    bool endOfFile = false;
    size_t ret;

    while (!endOfFile)
    { // Read file in chunks of 512 into buffer
        fread(buffer, 512, 1, inputPtr);
        if (foundJPEGheader(buffer))
        {
            // Create a string for filename
            sprintf(filename, "%03i.jpg", fileNum);
            fileNum++;
            // Open file for writing the image
            FILE *outPtr = fopen(filename, "w");

            while (!endOfFile)
            {
                // Write found image into output file
                fwrite(buffer, 512, 1, outPtr);
                ret = fread(buffer, 512, 1, inputPtr);

                if (foundJPEGheader(buffer))
                {
                    fclose(outPtr);
                    sprintf(filename, "%03i.jpg", fileNum);
                    fileNum++;
                    FILE *ouptr = fopen(filename, "w");
                }
                // If file end is reached, close and set endofFile to true to break the loop
                if (ret != 1)
                {
                    endOfFile = true;
                    fclose(outPtr);
                }
            }
        }
    }
    // Free allocated memory and close input file
    free(buffer);
    fclose(inputPtr);
}

void print_usage()
{
    printf("Usage: ./recover image\n");
}

bool foundJPEGheader(BYTE *buffer)
{
    // Check for JPEG headers
    if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
    {
        return true;
    }
    return false;
}