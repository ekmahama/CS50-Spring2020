#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void print_usage();
void print_farenheit(float c);
void print_centigrate(float f);

int main(int argc, char *argv[])
{
    int options;
    int cflag = 0;
    int fflag = 0;

    // Colon means argument after the option is mandatory
    while ((options = getopt(argc, argv, "c:f:")) != -1)
    {
        switch (options)
        {
        case 'c':
            if (cflag)
            {
                print_usage();
            }
            else
            {
                cflag++;
                fflag++;
            }
            print_centigrate(atof(optarg));
            break;

        case 'f':
            if (fflag)
            {
                print_usage();
            }
            else
            {
                fflag++;
                cflag++;
            }
            print_farenheit(atof(optarg));
            break;

        default:
            print_usage();
            break;
        }
    }
    return 0;
}

void print_usage()
{
    printf("Usage: ./getOpt -c n | ./ getOpt -f n ");
    exit(1);
}

void print_farenheit(float c)
{
    float f = ((c * 9) / 5) + 32;
    printf("Farenheit Equivalent: %.2f\n", f);
}

void print_centigrate(float f)
{
    float c = ((f - 32) * 5) / 9;
    printf("Centigrae Equivalent: %.2f\n", c);
}