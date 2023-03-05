// 1. Написати функцію, яка повертає мінімальне та максимальне значення з масиву.

#include <stdio.h>

int main()
{

    int arr[1000] = { 1,2,3,4,5,6,7,8,-10,-20,30,-100};
    size_t n =  sizeof(arr) / sizeof(arr[0]);
    int min = 2147483647 ;
    int max =  -2147483647;

        for (int i = 0; i <= n; i++)
        {
            if(arr[i] > max){
                max = arr[i];
            }
            if(arr[i] < min){
                min = arr[i];
            }
        }
    printf("max = %d min = %d  \n ",max, min);
    return 0;
}
