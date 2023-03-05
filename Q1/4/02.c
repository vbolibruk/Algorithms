// 2. Написати функцію, яка шукає елемент у невпорядкованому масиві. Функція повинна повертати індекс шуканого елементу або від'ємне число, якщо заданого елементу в масиві не має.

#include <stdio.h>

int main()
{

    int arr[1000] = { 1,2,3,4,5,6,7,8,-10,-20,30,-100};
    size_t n =  sizeof(arr) / sizeof(arr[0]);
    int indexOfNumber = -1 ;
    int numberToFind = -100;

        for (int i = 0; i <= n; i++)
        {
            if(arr[i] == numberToFind){
                indexOfNumber = i;
            }

        }
    printf("index of searched number  = %d   \n ",indexOfNumber);
    return 0;
}
