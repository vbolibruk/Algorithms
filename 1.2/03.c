// 4. Написати функції, які обчислють суму 1/1 + 1/2 +1/3 + ...+ 
// 1/N зліва направо і у зворотьому порядку. Порівняйте результати.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    double myNum, sum , i;
    printf("Enter number  \n");

    scanf("%lf", &myNum);
    printf("Num is, %lf \n", myNum);
    for (i =1; i <= myNum; ++i)
    {
        sum = sum + 1/i;

    }

    printf("Sum is, %lf \n", sum);
    return 0;
}
