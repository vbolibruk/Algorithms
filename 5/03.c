// 3. Написати рекурсивну функцію, що знаходить максимальний елемент в масиві.

#include <stdio.h>

int customRecursion(int arr[],int pos, int max);

int main()
{

    int arr[10] = {1,2,3,4,5,6,7,88,9,10};
    int result1;
    int max = -2147483647;


    result1=customRecursion(arr,9,max);

    printf("max element is = %d  \n ",result1);
    return 0;
}


int customRecursion(int n[], int length, int max){
     printf("n[length] %d , max  %d \n ",n[length] , max );
    int i = length-1;
    if(i<0){
        return max;
    }
    if(n[length]>max){
        max = n[length];
    }
    return customRecursion( n, i, max);
    
}