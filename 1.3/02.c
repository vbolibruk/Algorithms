// 3. Написати програму, яка динамічно виділяє пам'ять під масив та читає значення його елементів з консолі. Потім знаходить їх суму та виводить на екран. Пам'ять повинна бути звільнене після виконання програми.


#include <stdio.h>
#include <stdlib.h>
int main() {

    int *ptr;
    int myNum, i,sum = 0;
    printf("Enter number of elements \n");
    scanf("%d", &myNum);
    ptr = (int *)malloc(myNum * sizeof(int));

    for (i = 0; i < myNum; ++i)
    {
        scanf("%d" , &ptr[i]);
        sum += ptr[i];
        printf("we put element %d in array \n" , ptr[i]);
    }
    printf("sum %d  \n" , sum);
    free(ptr);
    return 0;
}