// "1. Алгоритм швидкого піднесення до степеня (exponentiating by squaring)
// Написати функцію, яка розраховує a^n використовуючи алгоритм швидкого піднесення до степеня"
#include <stdio.h>
#include <math.h>
#include <assert.h>

void baseToPowerOfn(double base, unsigned n);
double power(double x, int n);

// number
double base = 3;
// power
unsigned n = 3;

int j = 0;
double result = 1;
int main()
{

    // option 1
    printf(" option 2 \n");
    baseToPowerOfn(3, 3);
    assert(result == pow(3, 3));
    printf("%lf result of 3^3 \n", result);

    result = 1;
    baseToPowerOfn(3, 4);
    assert(result == pow(3, 4));
    printf("%lf result of 3^4 \n", result);

    result = 1;
    baseToPowerOfn(12.2, 4);
    assert(result == pow(12.2, 4));
    printf("%lf result of 12.2^4 \n", result);

    printf(" option 2 \n");
    // option 2
    double res = power(3, 3);
    assert(res == pow(3, 3));
    printf("%lf result of 3^3 \n", res);

    double res2 = power(1.5, 35);
    // assert(res2 == pow( 1.5, 35 ));
    printf("%lf pow result of 1.5^35 \n",  pow( 1.5, 35 ));
    printf("%lf power result of 1.5^35 \n", res2);


    double res3 = power(23, 3);
    assert(res3 == pow(23, 3));
    printf("%lf result of 23^3 \n", res3);


    return 0;
}

void baseToPowerOfn(double base, unsigned n)
{
    if (n > 1)
    {
        j++;
        baseToPowerOfn(base, n >> 1);
    }
    if ((n & 1) == 1 && j != 0)
    {
        double power = result * base;
        result = power * power;
    }
    if ((n & 1) == 0 && j != 0)
    {
        result = result * result;
    }
    if ((n & 1) == 1 && j == 0)
    {
        result = result * base;
    }
    j--;
}

double power(double x, int y)
{
    float res = 1;

    // Check till the power becomes zero
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if ((y & 1) == 1)
            res = (res * x);
        y = y >> 1;
        // Change x to x^2
        x = (x * x);
    }
    return res;
}