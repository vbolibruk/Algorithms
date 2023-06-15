// Випишіть як буде виглядати масив після кожної ітерації алгортму, якщо його початковий стан <31, 41, 59, 26, 41, 58>
// Answer
// 1. 26, 41, 59, 31, 41, 58
// 2. 26, 31 , 59, 41 , 41, 58
// 3. 26, 31 , 41 , 59 , 41, 58
// 4. 26, 31 , 41 , 41 ,59, 58
// 5. 26, 31 , 41 , 41 ,58 , 59

// Як буде працювати алгоритм, якщо його початковий стан <1, 2, 3, 4, 5, 6> ?
// буде проходити всі ітераціі

// Як буде працювати алгоритм, якщо його початковий стан <6, 5, 4, 3, 2, 1> ?
// буде проходити всі ітераціі як и вище

// Як буде працювати алгоритм, якщо його початковий стан <3, 3, 3, 3, 3, 3> ?
// буде проходити всі ітераціі як и вище

// Оцініть час роботи алгоритму в цих 4-х випадках?
// // 1 - ON^2 ,  2 - ON^2 , 3 - ON^2
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
// void selectionSort(int array[], int arraySize)
// {
//     int i, j, min_index;
//     int num1, num2;
//     for (i = 0; i < arraySize; i++)
//     {
//         min_index = i;
//         for (j = i + 1; j < arraySize; j++)
//         {
//             if (array[j] < array[min_index])
//             {
//                 min_index = j;
//             }

//         }
//                     if (min_index != i)
//             {
//                 swap(&array[min_index], &array[i]);
//             }
//     }
// }

void selectionSort(int array[], int n)
{
    int i, j, k, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (array[j] < array[i])
            {
                min_idx = j;
            }
            if (min_idx != i)
            {
                swap(&array[j], &array[i]);
            }
        }
    }
}
