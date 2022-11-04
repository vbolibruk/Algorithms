// "3. Бінарний пошук (Binary Search)
// Написати функцію, яка шукає елемент у впорядкованому масиві використовуючи алгоритми бінарного пошуку."

#include <stdio.h>

int main()
{

    int arr[1000] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 50};
    int n = 11;

    int leftIndex = 0;
    int rightIndex = n;
    int m;
    int searchedNumber = 50;

    while (leftIndex <= rightIndex)
    {

        printf("before leftIndex  %d , rightIndex  = %d , m = %d \n ", leftIndex, rightIndex, m);
        m = (rightIndex + leftIndex) / 2;

        if (arr[m] == searchedNumber)
        {                 
            break;       
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
    printf(" searched number  = %d   ,  index = %d \n ", arr[m], m);
    return 0;
}
