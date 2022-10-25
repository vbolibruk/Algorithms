// "2. Алгоритм Евкліда (Euclidean algorithm)
// Написати функцію, яка знаходить найбільший спільний дільник двох чисел за алгоритмом Евкліда"
#include <stdio.h>

int commonDiv(int a, int b);

int main()
{
    int firstN, secondN, tempStor, i;

    printf("Enter 1st num \n");
    scanf("%d", &firstN);

    printf("Enter 2nd num \n");
    scanf("%d", &secondN);

    // make sure firstN  always big one
    if (secondN > firstN)
    {
        tempStor = secondN;
        firstN = secondN;
        secondN = tempStor;
    }

    i = commonDiv(firstN,secondN);
    printf("Greates common div num %d \n", i);
    return 0;
}

int commonDiv(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return commonDiv(b, a % b);
    }
}