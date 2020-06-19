#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>

/*
* for i = 0 to n-1:
*   select the smallest element and put it at the beginning of the list
*/

void printArray(int arr[], int n);
void visualizeSort(int arr[], int n);

int main(int argc, char *argv[])
{
    int array[] = {21, 9, 18, 14, 3, 7, 2, 19, 20, 10, 8, 1, 5,-2,-18};
    //int array[] = {1, 2, 3, 3, 4, 5, 6, 7, 8, 9,10, 11};

    int sz = sizeof(array) / sizeof(int);
    printf("sz = %i\n", sz);

    for (int i = 0; i < sz; i++)
    {
        int index = i;
        int smaller = array[i];
        //printf("Smaller before: %i\n", smaller);

        for (int j = i; j < sz - 1; j++)
        {
            if (array[j + 1] < smaller)
            {
                smaller = array[j + 1];
                index = j + 1;
            }
        }

        //printf("Smaller after: %i\n", smaller);
        int temp = array[i];
        array[i] = array[index];
        array[index] = temp;

        visualizeSort(array, sz);
        printf("\n");
        printArray(array, sz);

        sleep(2); // sleep for 3 seconds
    }

    return 0;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void visualizeSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        for (int j = 0; j < num; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}