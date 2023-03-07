// Випишіть як буде виглядати масив після кожної ітерації алгортму, якщо його початковий стан <31, 41, 59, 26, 41, 58>

// 1 <31, 41, 59, 26, 41, 58>
// 2 <31, 41, 59, 26, 41, 58>
// 3 <26 , 31, 41, 59, 41, 58>
// 4 <26 , 31, 41, 41, 59 , 58>
// 5 <26 , 31, 41, 41, 58 ,59  >

// Як буде працювати алгоритм, якщо його початковий стан <1, 2, 3, 4, 5, 6> ?
//масив не зміниться але перевірка усе одно пройде всі елементи

// Як буде працювати алгоритм, якщо його початковий стан <6, 5, 4, 3, 2, 1> ?
//масив  зміниться , перевірка усе одно пройде всі елементи,буде проходити всі ітераціі як и вище

// Як буде працювати алгоритм, якщо його початковий стан <3, 3, 3, 3, 3, 3> ?
//буде проходити всі ітераціі як и вище

// Оцініть час роботи алгоритму в цих 4-х випадках?
// 1 - ON ,  2 - ON^2 , 3 - ON
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