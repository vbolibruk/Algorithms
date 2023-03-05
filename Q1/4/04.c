// 4. Написати модифіковану версію бінарного пошуку, яка повертає мінімільний індекс заданого елементу (припускаючи, що елементи масиву можуть дублюватися)

#include <stdio.h>

int main()
{

    int arr[1000] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 50 , 50 , 50};
    int n = 13;

    int leftIndex = 0;
    int rightIndex = n;
    int m;
    int searchedNumber = 50;
    int result  = -1;

    while (leftIndex <= rightIndex)
    {

        printf("before leftIndex  %d , rightIndex  = %d , m = %d \n ", leftIndex, rightIndex, m);
        m = (rightIndex + leftIndex) / 2;

        if (arr[m] == searchedNumber)
        {      
            result = m;
            rightIndex = m - 1;           
        }

        if (arr[m] < searchedNumber)
        {
            leftIndex = m + 1;
        }
        else if (arr[m] > searchedNumber)
        {
            rightIndex = m - 1;
        }

        printf("after leftIndex  %d , rightIndex  = %d , m = %d \n ", leftIndex, rightIndex, m);
    }
    printf(" searched number  = %d   ,  index = %d \n ", arr[result], result);
    return 0;
}
