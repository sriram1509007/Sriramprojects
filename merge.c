#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Function prototypes
void mergeSort(int array[], int length);
void merge(int leftArray[], int leftSize, int rightArray[], int rightSize, int array[]);

int main()
{
    int array[] = {8, 2, 5, 3, 4, 7, 6, 1};
    int length = sizeof(array) / sizeof(array[0]);

    mergeSort(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void mergeSort(int array[], int length)
{
    if (length <= 1)
        return; // base case

    int middle = length / 2;

    // Dynamic heap allocation
    int *leftArray = malloc(middle * sizeof(int));
    int *rightArray = malloc((length - middle) * sizeof(int));

    // Defensive check: Ensure allocation didn't fail
    if (leftArray == NULL || rightArray == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    int l_idx = 0; // explicit left array tracker
    int r_idx = 0; // explicit right array tracker

    for (int i = 0; i < length; i++)
    {
        if (i < middle)
        {
            leftArray[l_idx] = array[i];
            l_idx++;
        }
        else
        {
            rightArray[r_idx] = array[i];
            r_idx++;
        }
    }

    // Recursive sorting calls
    mergeSort(leftArray, middle);
    mergeSort(rightArray, length - middle);

    // Combine arrays
    merge(leftArray, middle, rightArray, length - middle, array);

    // CRITICAL: Free the allocated heap memory to avoid memory leaks
    free(leftArray);
    free(rightArray);
}

void merge(int leftArray[], int leftSize, int rightArray[], int rightSize, int array[])
{
    int i = 0, l = 0, r = 0;

    while (l < leftSize && r < rightSize)
    {
        if (leftArray[l] < rightArray[r])
        {
            array[i] = leftArray[l];
            i++;
            l++;
        }
        else
        {
            array[i] = rightArray[r];
            i++;
            r++;
        }
    }

    while (l < leftSize)
    {
        array[i] = leftArray[l];
        i++;
        l++;
    }
    while (r < rightSize)
    {
        array[i] = rightArray[r];
        i++;
        r++;
    }
}