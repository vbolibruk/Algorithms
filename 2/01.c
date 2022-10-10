// 2. Написати програму яка знаходить та зберігає у масиві всі прості числа від 1 до n, а потім виводить їх на екран. Використати функцію з попереднього завдання.

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n);
int main()
{
    int maxNumber = 100, i, lastElement = 0;
    int arrOfPrimes[100];
    for (i = 0; i < maxNumber; ++i)
    {
        if (isPrime(i))
        {
            arrOfPrimes[lastElement] = i;
            lastElement++;
        }
    }
    for (i = 0; i < lastElement; i++)
        printf("%d ", arrOfPrimes[i]);

    return 0;
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