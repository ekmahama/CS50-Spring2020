
/* Binary Search */
#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>

int binarySearch(int array[], int n, int sz);
void printArray(int arr[], int n);

int main(int argc, char *argv[])
{
    int searchItem = atoi(argv[1]);
    int array[] = {-5, -3, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 18, 23, 27, 34, 39};
    int sz = sizeof(array) / sizeof(int);

    printArray(array, sz);
    int res = binarySearch(array, searchItem, sz);
    if (res == sz)
    {
        printf("%i found in array\n", res);
    }
    else
    {
        printf("%i not found found in array\n", searchItem);
    }

    return 0;
}

int binarySearch(int array[], int n, int sz)
{
    if (sz >= 1)
    {

        int m = sz / 2;

        printf("middle = %i\n", array[m]);
        if (array[m] == n)
        {
            return array[m];
        }

        else
        {
            if (n < array[m])
            {
                int lArry[m];
                for (int i = 0; i < m; i++)
                {
                    lArry[i] = array[i];
                }
                printf("Left Array: ");
                printArray(lArry, m);
                return binarySearch(lArry, n, m);
            }
            else
            {
                int szR = sz - m - 1;
                int RArry[szR];

                for (int j = 0; j < szR; j++)
                {
                    RArry[j] = array[m + j + 1];
                }
                printf("Right Array: ");
                printArray(RArry, szR);
                return binarySearch(RArry, n, szR);
            }
        }
    }
    return 9999;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}