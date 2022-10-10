// "1. Прості числа (prime numbers)
// Написати функцію, яка перевіряє чи є число простим. Функція повинна працювати оптимально: перебираючи всі дільники від 1 до sqrt(n) та зупиняючись, коли дільник знайдений"

// Если число не простое, то оно имеет как минимум два множителя, которые должны быть меньше(либо равны) корня из исходного числа, иначе бы их произведение было бы больше оного, поэтому нет смысла перебирать стоящие далее числа.


#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n);
int main()
{

    printf("3 isPrime %s \n", isPrime(3) ? "true" : "false");
    printf("4 isPrime %s \n", isPrime(4) ? "true" : "false");
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