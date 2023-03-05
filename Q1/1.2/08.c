// 9. Написати програму, яка виводить на екран значення функції x^3 на проміжку від a до b з кроком h, a, b та h вводяться користувачем.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int i, a, b, h;
    printf("Enter a number  \n");
    scanf("%d", &a);

    printf("Enter b number  \n");
    scanf("%d", &b);

    printf("Enter h number  \n");
    scanf("%d", &h);

    if (b < a)
    {
        printf("a should be > b  \n");
    }
    if (h > b)
    {
        printf("h should be < b  \n");
    }

    for (i = a; i <= b; i += h)
    {
        printf("i %d \n",i );
        printf(" pow %lf \n", pow(i, 3));
    }
    return 0;
}
