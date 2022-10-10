// "3. Решето Ератосфена (Sieve of Eratosthenes)
// Написати програму, яка виводить усі прості числа на проміжку від 1 до n, де n задається користувачем."

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n);
#define N 100
//алгоритм "решето Эратосфена"
unsigned int a[N];
void main()
{
    int i;
    //заполним все ячейки числами по порядку: 0,1,2,3...
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
    }
    //поскольку 1 не простое число, обнулим ячейку с этим числом
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
    for (i = 0; i < N; i++)
    {
        if (a[i] != 0)
        {
            printf("%d ", a[i]);
        }
    }
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