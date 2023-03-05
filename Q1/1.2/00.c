// 1. Написати програму, яка виводить на екран числа від 1 до n, де n вводиться користувачем. Використати цикл for
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{

    int *ptr;
    int myNum, i;
    printf("Enter number of elements \n");
    scanf("%d", &myNum);

    ptr = (int *)malloc(myNum * sizeof(int));
    printf("The elements of the array are: ");
    for (i = 0; i < myNum; ++i)
    {
        ptr[i] = i + 1;
        printf("%d, ", ptr[i]);
    }

    return 0;
}
