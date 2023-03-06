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
void insertionSort(int array[], int arraySize);

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
    insertionSort(ptr, arraySize);
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
void insertionSort(int array[], int arraySize)
{
    int i, j, value;
    int num1, num2;
    for (i = 1; i < arraySize; i++)
    {
        value = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > value)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = value;
    }
}