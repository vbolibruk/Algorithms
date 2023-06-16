

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b);
int findMinInArray(int array[], int arraySize);
void multiply(int arraySizeI, int arraySizeJ, int array[arraySizeI][arraySizeJ], int mult);

#define rows1 2 // number of rows in Matrix-1
#define columns1 2 // number of columns in Matrix-1
#define rows2 2 // number of rows in Matrix-2
#define columns2 2 // number of columns in Matrix-2
  
void mulMat(int mat1[][columns1], int mat2[][columns2])
{
    int resultM[rows1][columns2];
//   ROWS_A x COLS_B
    printf("Multiplication of given two matrices is:\n");
  
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            resultM[i][j] = 0;
  
            for (int k = 0; k < columns1; k++) {
                resultM[i][j] += mat1[i][k] * mat2[k][j];
            }
  
            printf("%d\t", resultM[i][j]);
        }
  
        printf("\n");
    }
}


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


    int mat1[rows1][columns1] = { { 1, 1 },
                         { 4, 4 } };
  
    int mat2[rows2][columns2] = { { 1, 1 },
                         { 3, 3 } };
  
  
    if (columns1 != rows2) {
        printf("The number of columns in Matrix-1  must be "
               "equal to the number of rows in "
               "Matrix-2\n");
               return 0;
  
    }
  
      // Function call
    mulMat(mat1, mat2);

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