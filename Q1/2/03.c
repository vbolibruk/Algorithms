// 4. Порівняти час роботи програм із задач 2 та 3 для різних n.
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

bool isPrime(int n);

int main()
{
    int i, s, N = 10000;
    int a[N];
    clock_t t;

    t = clock();
    int maxNumber = N, lastElement = 0;
    int arrOfPrimes[N];

    printf("1st algo started \n ");

    for (i = 0; i < maxNumber; ++i)
    {
        if (isPrime(i))
        {
            arrOfPrimes[lastElement] = i;
            lastElement++;
        }
    }
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("isPrime took %f seconds to execute \n", time_taken);

    t = clock();
    // for (i = 0; i < lastElement; i++)
    //     printf("%d ", arrOfPrimes[i]);

    printf("2nd algo started \n ");

    // fill array with 0,1,2,3...
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
    }
    // 1 is not prime lets assign 0
    a[1] = 0;
    for (int s = 2; s < N; s++)
    {
        if (a[s] != 0)
        {
            for (int j = s * 2; j < N; j += s)
            {
                a[j] = 0;
            }
        }
    }
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("smart algo took %f seconds to execute \n", time_taken);

    // for (i = 0; i < N; i++)
    // {
    //     if (a[i] != 0)
    //     {
    //         printf("%d ", a[i]);
    //     }
    // }
}

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}