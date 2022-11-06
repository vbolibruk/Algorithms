// "9. Правило Горнера (Horner's Rule)
// Написати ітеративну та рекурсивну функції, які розраховують значення полінома за правилом Горнера"

#include <stdio.h>
int customRecAlgo(int n);

int main()
{

    int n = 8;
    int result;
    result = customRecAlgo(n);

    printf("result  = %d \n ", result);
    return 0;
}

// 0 + (10 * (0 + 10 * (0 + 10 * ( 1 + 10 * 0))
int customRecAlgo(int n)
{
    if (n == 0)
        return 0;
    else
        return (n % 2 + 10 *
                customRecAlgo(n / 2));
}

