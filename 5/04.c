// 4. Написати рекурсивну функцію, що знаходить суму додатніх елементів масиву.
#include <stdio.h>

int customRecursion(int arr[],int pos, int max);

int main()
{

    int arr[10] = {-1,-2,-3,-4,-5,-6,-7,88,1,10};
    int result1;
    int sum = 0;


    result1=customRecursion(arr,9,sum);

    printf("sum of elements is = %d  \n ",result1);
    return 0;
}


int customRecursion(int n[], int length, int sum){
    int i = length-1;
    if(i<0){
        return sum;
    }
    if(n[length]>0){
        sum = sum + n[length];
    }
    return customRecursion( n, i, sum);
    
}