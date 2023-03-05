// 10. Написати функцію, яка розраховує значення функції cos використовуючи її розклад у ряд Тейлора (у точці 0). Функція приймає два аргументи: x та n, де x аргумент функції cos, n кількість перших членів ряду.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long getFact(int) ;

int main(void)
{
    int i, x, n ;
    unsigned long long fac;
    double sum;
    printf("Enter x number  \n");
    scanf("%d", &x);
    

    printf("Enter n number  \n");
    scanf("%d", &n);

    // fac =   getFact(4);
    // printf("getFact %llu \n", fac);

    for (i = 0; i <= n; ++i)
    {
        printf("i %d \n", -i);

        sum +=  (pow(-1, i)/getFact(2*i))*pow(x, 2*i);
    }
    printf(" sum %lf \n", sum);
    return 0;
}

long getFact(int n)
{
    int  i;
    unsigned long long fact = 1;

    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");
    else
    {
        for (i = 1; i <= n; ++i)
        {
            fact *= i;
        }
        // printf("Factorial of %d = %llu  \n", n, fact);
    }
    return fact;
}