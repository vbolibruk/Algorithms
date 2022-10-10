// 8. Написати програму, що знаходить суму цифр цілого числа n. n вводиться користувачем, 0 < n < 10^10
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int myNumN;
    int sum = 0;
    long border = 10000000000;
    div_t intPartAfterDivision;
    printf("Enter n number  \n");
    scanf("%d", &myNumN);
    printf("n is %d\n", myNumN);

    if (myNumN > border)
    {
        printf("Too match");
        return 0;
    }

    if (myNumN < 10)
    {
        printf("sum is %d\n", myNumN);
        return 0;
    }

    printf("myNumN is %d\n", myNumN);

    while (myNumN > 0)
    {
        intPartAfterDivision = div(myNumN, 10);
        sum = sum + intPartAfterDivision.rem;
        myNumN = intPartAfterDivision.quot;

        printf("rem is %d\n", intPartAfterDivision.rem);
        printf("quot is %d\n", intPartAfterDivision.quot);
        printf("\n");
    }
    printf("sum is %d\n", sum);

    return 0;
}
