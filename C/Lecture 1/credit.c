#include <stdio.h>
#include "cs50.h"

int get_checksum(long number);
int get_length(long n);
int get_first2_dig(long n, int cnt);

int main()
{
    long number = get_long("Number: ");
    // printf("number: %li\n", number);
    int res = get_checksum(number);
    int cnt = get_length(number);
    int initial = get_first2_dig(number, cnt);

    if (!(res % 10))
    {
        // printf("Valid\n");

        if ((cnt == 15) && ((initial == 34) || (initial == 37)))
        {
            printf("AMEX\n");
        }

        else if ((cnt == 16) && ((initial >= 51) && (initial <= 55)))
        {
            printf("MASTERCARD\n");
        }

        else if (((cnt == 13) || (cnt == 16)) && ((initial / 10) == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    printf("Checksum: %i\n", res);
    printf("Length: %i\n", cnt);
    printf("Initial: %i\n", initial);

    return 0;
}

int get_checksum(long number)
{
    // Accumulate digits of sum of products
    int sumProd = 0;

    // Accumulate digits that werent multiplied
    int sumRest = 0;

    // Variable to hold each product
    int prod;

    // Set to false if digit is not multiplied by 2
    bool sP = false;

    // Set true is if digit is not multiplied by 2
    bool sR = true;

    // Start of getting each digit from the long
    while (number > 0)
    {
        int digit = number % 10; // Get t

        if (sP)
        {
            // Branch for digit that need mulitplication
            prod = 2 * digit;
            printf("%i\n", prod);

            // Seperating the products into digits and summing

            int inD = prod % 10;
            sumProd += inD;
            sumProd += (prod / 10);

            printf("Inner D: %i\n", inD);

            sR = true;
            sP = false;
        }
        else
        {
            // Branch for digit requiring no multiplication
            sumRest += digit;
            sR = false;
            sP = true;
        }
        number /= 10;
        printf("%i\n", digit);
    }
    return (sumProd + sumRest);
}

int get_length(long n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int get_first2_dig(long n, int cnt)
{
    long initial;
    while (cnt > 2)
    {
        initial = n / 10;
        n /= 10;
        cnt--;
        //printf("Initial: %li\n", initial);
    }
    return initial;
}