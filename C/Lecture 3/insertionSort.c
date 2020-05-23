#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>

void printArray(int arr[], int n);
void visualizeSort(int arr[], int n);

int main(int argc, char const *argv[])
{
    int grades[] = {21, 9, 18, 14, 3, 7, 2, 19, 20, 10, 8, 1, 5, -2, -18};
    int n = sizeof(grades) / sizeof(float);
    int temp;
    // Assume first element i.e. 21 is sorted
    // Thus consider the remain portion of the array
    int startOfNextArray = 1;
    for (int i = startOfNextArray; i < n; i++)
    {
        for (int j = 0; j < startOfNextArray; j++)
        {
            if (grades[i] < grades[j])
            {
                temp = grades[i];
                grades[i] = grades[j];
                grades[j] = temp;
            }
        }
        startOfNextArray++;

        visualizeSort(grades, n);
        printf("\n");
        printArray(grades, n);
         sleep(2); // sleep for 3 seconds
    }

    // visualizeSort(grades, n);
    // printf("\n");
    // printArray(grades, n);

   

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