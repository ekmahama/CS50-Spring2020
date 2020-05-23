#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>

void printArray(int arr[], int n);
void visualizeSort(int arr[], int n);

int main(int argc, char *argv[])
{
    int array[] = {21, 9, 18 , 14, 3, 7, 2, 19, 20, 10, 8, 1, 5};
    //int array[] = {1, 2, 3, 3, 4, 5, 6, 7, 8, 9,10, 11};

    int sz = sizeof(array) / sizeof(int);
    printf("sz = %i\n", sz);

    for (int i = 0; i < sz - 1; i++)
    {
        bool sorted = true;
        for (int j = 0; j < sz - (i + 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                sorted = false;
                printf("swaped, j = %i\n", j);
            }
        }

        visualizeSort(array, sz);
        printf("\n");
        printArray(array, sz);
        
        if (sorted)
        {
            break;
        }
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