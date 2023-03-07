

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b);
int findMinInArray(int array[], int arraySize);
void multiply(int arraySizeI, int arraySizeJ, int array[arraySizeI][arraySizeJ], int mult);

int main(void)
{

    int *ptr;
    int arraySize, i, j, itemToFind;
    int c[2][3] = {{1, 3, 0}, {-1, 5, 9}};

    srand(time(NULL));
    printf("Enter number of elements \n");
    scanf("%d", &arraySize);
    ptr = (int *)malloc(arraySize * sizeof(int));

    printf("elements of the array are: ");
    for (i = 0; i < arraySize; ++i)
    {
        ptr[i] = rand() % 10;
        printf("%d, ", ptr[i]);
    }
    itemToFind = findMinInArray(ptr, arraySize);
    printf("\n");
    printf("The min elements of the array is: ");
    printf("%d, ", itemToFind);
    printf("\n");

    multiply(2, 3, c, 10);
    // for (i = 0; i < arraySize; ++i)
    // {
    //     printf("%d, ", ptr[i]);
    // }
    return 0;
}

// swap sample
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMinInArray(int array[], int arraySize)
{
    int i;
    int min_item = array[0];
    for (i = 0; i < arraySize; i++)
    {
        if (array[i] < min_item)
        {
            min_item = array[i];
        }
    }
    return min_item;
}

void multiply(int arraySizeI, int arraySizeJ, int array[arraySizeI][arraySizeJ], int mult)
{
    int i, j;
    for (i = 0; i < arraySizeI; i++)
    {
        for (j = 0; j < arraySizeJ; j++)
        {
            array[i][j] = array[i][j] * mult;
        }
    }
    for (i = 0; i < arraySizeI; i++)
    {
        for (j = 0; j < arraySizeJ; j++)
        {
            printf("%d, ", array[i][j]);
        }
    }
}