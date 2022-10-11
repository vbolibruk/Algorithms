// "3. Решето Ератосфена (Sieve of Eratosthenes)
// Написати програму, яка виводить усі прості числа на проміжку від 1 до n, де n задається користувачем."

#include <stdio.h>

int main()
{
    int i,s , N=100;
    int a[N];
    //fill array with 0,1,2,3...
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
    }
    //1 is not prime lets assign 0
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

