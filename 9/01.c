// "1. Алгоритм швидкого піднесення до степеня (exponentiating by squaring)
// Написати функцію, яка розраховує a^n використовуючи алгоритм швидкого піднесення до степеня"
#include <stdio.h>
#include <math.h>
#include <assert.h>

void baseToPowerOfn(double base, unsigned n);


// number 
double base = 3;
// power
unsigned n = 3;
double result = 1;
int j = 0;

int main()
{

    baseToPowerOfn(3, 3);
    assert(result == pow( 3, 3 ));
    printf("%lf result of 3^3 \n", result);

    result = 1;
    baseToPowerOfn(3, 4);
    assert(result == pow( 3, 4 ));
    printf("%lf result of 3^4 \n", result);


    result = 1;
    baseToPowerOfn(12.2, 4);
    assert(result == pow( 12.2, 4 ));
    printf("%lf result of 1.5^35 \n", result);

    return 0;
}

void baseToPowerOfn(double base , unsigned n)
{
    if (n > 1)
    {
        j++;
        baseToPowerOfn(base,n >> 1);
    }
    if ((n & 1) == 1 && j!=0)
    {
        double power = result * base;
        result = power * power;
    }
    if ((n & 1) == 0 && j!=0)
    {
        result = result * result;
    }
    if ((n & 1) == 1 && j==0)
    {
        result = result * base;
    }   
    j--;
}
