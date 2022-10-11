
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