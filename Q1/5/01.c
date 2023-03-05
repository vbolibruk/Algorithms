//1. Напишіть ітеративну та рекурсивну функції, які розраховують N!

#include <stdio.h>

int factIteration(int n);
int factRecursion(int n);

int main()
{

    int n = 9;
    int result1;
    int result2;

    result1=factIteration(n);
    result2=factRecursion(n);

    printf("1st n! = %d , 2nd n! = %d \n ",result1,result2);
    return 0;
}

int factIteration(int n){
    if(n==1){
        return 1;
    }
    int result = 1;
    for (int i=1; i <= n; i++){
        result = i * result ;
    }
    return result;
}

int factRecursion(int n){
    if(n==1){
        return 1;
    }
    int result = n * factRecursion(n-1);
    return result;
}