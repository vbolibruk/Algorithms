// Реалізувати алгоритм Bubble Sort
// Реалізувати мовою C приклад з вказівниками
// Реалізувати мовою C функцію swap

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b);
void sort(int *array, int arraySize);

int main(void)
{

    int *ptr;
    int arraySize, i, j;
    srand(time(NULL));
    printf("Enter number of elements \n");
    scanf("%d", &arraySize);
    // pointer sample
    ptr = (int *)malloc(arraySize * sizeof(int));

    printf("The unsorted elements of the array are: ");
    for (i = 0; i < arraySize; ++i)
    {
        ptr[i] = rand() % 10;
        printf("%d, ", ptr[i]);
    }
    sort(ptr, arraySize);
    printf("\n");
    printf("The sorted elements of the array are: ");

    for (i = 0; i < arraySize; ++i)
    {
        printf("%d, ", ptr[i]);
    }
    return 0;
}

// swap sample
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort sample
void sort(int *array, int arraySize)
{
    int i, j;
    int num1, num2;
    for (i = 0; i < arraySize; i++)
    {
        for (j = arraySize-1; j > i; j--)
        {
            if (array[j] < array[j - 1])
            {

                num1 = array[j];
                num2 = array[j - 1];
                // printf("Before Swapping: num1 is: %d, num2 is: %d\n", num1, num2);
                swap(&num1, &num2);
                // printf("After  Swapping: num1 is: %d, num2 is: %d\n", num1, num2);
                array[j] = num1;
                array[j - 1] = num2;
            }
        }
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n  - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
 
        // If no two elements were swapped by inner loop,
        // then break

    }
}