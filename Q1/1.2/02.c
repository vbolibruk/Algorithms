// 3. Написати програму, яка читає введені користувачем цілі числа до тих пір, доки не буде введено 0. Після вводу числа 0 виводить кількість введених чисел (крім 0) та їх суму.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int myNum, sum = 0, i = 0;
    printf("Enter numbers  \n");

    do
    {
        scanf("%d", &myNum);
        printf(" myNum  is, %d \n", myNum);
        sum = sum + myNum;
        i++;
    } while (myNum != 0);

    printf("Sum is, %d \n", sum);
    printf("Count is, %d \n", i);
    return 0;
}
