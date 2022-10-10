// "5. Написати програму яка виводить на екран послідовність:
// 1 n
// 2 n-1
// ...
// n 1
// Реалізувати вивід двома способами: використовуючи два ітератори, використовуючи лише один ітератор
// Приклад:
// Вхід:
// 8
// Вихід:
// 1 8
// 2 7
// 3 6
// 4 5
// 5 4
// 6 3
// 7 2
// 8 1"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int myNum, i, displayI = 0, displayMyNum, *data;
    printf("Enter number  \n");

    scanf("%d", &myNum);
    printf("Num is, %d\n", myNum);
    data = (int *)malloc(myNum * sizeof(int));
    // one iterator
    displayMyNum = myNum;
    for (i = 0; i < myNum; ++i)
    {
        displayI++;
        printf("%d %d\n", displayI, displayMyNum);
        displayMyNum--;
    }

    // two iterators
    displayMyNum = myNum;
    displayI = 0;
    for (i = 0; i < myNum; ++i)
    {
        displayI++;
        data[i] = displayI;
    }

    for (i = 0; i < myNum; ++i)
    {
        printf("%d %d\n", data[i], displayMyNum);
        displayMyNum--;
    }
    return 0;
}
