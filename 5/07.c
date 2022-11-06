// 7. Написати функцію, яка шукає елемент у впорядкованому масиві використовуючи рекурсивний алгоритми бінарного пошуку.
#include <stdio.h>

int binSearch(int n[], int leftIndex , int rightIndex,  int searchedNumber);

int main(){

    int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 50};
    int n = 11;
    int searchedNumber = 50;
    int result = -1;

    result = binSearch(arr, 0, 11  , 50);
    printf("index  = %d , number  = %d \n ", result, arr[result]);
    return 0;


}
int binSearch(int arr[], int leftIndex , int rightIndex, int searchedNumber )
{

        int m = (rightIndex + leftIndex) / 2;

        if (arr[m] == searchedNumber)
        {                 
            return m;      
        }

        if (arr[m] < searchedNumber)
        {
            leftIndex = m + 1;
        }
        else if (arr[m] > searchedNumber)
        {
            rightIndex = m - 1;
        }
        return binSearch(arr,leftIndex ,  rightIndex,  searchedNumber );

}
