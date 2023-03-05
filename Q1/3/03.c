// 3. Написати програму, яка розкладає задане число на прості множники. Наприклад: 140: 2*2*5*7
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int a, int b);
long fact(int n);


// Function to calculate the factorial
long fact(int n)
{
    int factm = 1;
    int m = n - 1;

    // find factorial of n-1
    for (int i = 1; i <= m; i++)
    {
        factm *= i;
    }
    return factm;
}

// Function to check if the
// number is prime or not
bool isPrime(int factm, int n)
{
    // add 1 to (n-1)!
    int factn = factm + 1;
    if (factn % n == 0)
    {
        // if remainder is 0
        // printf(" %d  is prime number", n);
        return true;
    }
    else
    {
        // printf("%d  is not prime number", n);
        return false;
    }
    return 0;
}
int main()
{

    int n, div = 2;
    int ii = 0;
    int arr[1000];

    printf("Enter num \n");
    scanf("%d", &n);

    long factm = fact(n);
    bool isPrimeFlag = isPrime(factm, n);
    if (isPrimeFlag)
    {
        printf("number is prime! \n no dividers");
    }
    else
    {
        while (n > 1)
        {
            while (n % div == 0)
            {
                arr[ii] = div;
                n = n / div;
                ii++;
            }
            div++;
        }
        for (int i = 0; i < ii; i++)
        {
            printf("%d i dividor = %d  \n ",i, arr[i]);
        }
    }

    return 0;
}
