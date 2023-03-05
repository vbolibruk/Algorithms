// Випишіть як буде виглядати масив після кожної ітерації алгортму, якщо його початковий стан <31, 41, 59, 26, 41, 58>
// Як буде працювати алгоритм, якщо його початковий стан <1, 2, 3, 4, 5, 6> ?
// Як буде працювати алгоритм, якщо його початковий стан <6, 5, 4, 3, 2, 1> ?
// Як буде працювати алгоритм, якщо його початковий стан <3, 3, 3, 3, 3, 3> ?
// Оцініть час роботи алгоритму в цих 4-х випадках?
// Реалізувати алгоритм Selection Sort


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b);
void selectionSort(int array[], int arraySize);

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
    selectionSort(ptr, arraySize);
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

// selection sort sample
void selectionSort(int array[], int arraySize)
{
    int i, j;
    int num1, num2;
    for (i = 0; i < arraySize; i++)
    {
        for (j = arraySize-1; j > i; j--)
        {
            if (array[j] < array[j - 1])
            {
                swap(&array[j], &array[j - 1]);
            }
        }
    }
}