// 2. Напишіть рекурсивну функцію, які розраховують суму ряду: 1+2+...+N

#include <stdio.h>

int customRecursion(int n);

int main()
{

    int n = 10;
    int result1;

    result1=customRecursion(n);

    printf("1st n! = %d  \n ",result1);
    return 0;
}


int customRecursion(int n){
    if(n==1){
        return 1;
    }
    int result = n + customRecursion(n-1);
    return result;
}