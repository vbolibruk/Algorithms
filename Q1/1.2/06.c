// "7. Написати програму, яка виводить на екран числа від 1 до n, причому в кожному рядку повинно бути не більше m чисел. n >= m. n та m вводяться користувачем.
// Розв'язати задачу двома способами: через владений цикл та використовуючи лише один цикл.
// Приклад:
// вхід:
// 10 4
// вихід:
// 1 2 3 4
// 5 6 7 8
// 9 10"
// TODO 2
#include <stdio.h>
#include <math.h>

int main(void)
{
    int myNumN, myNumM, counter = 0, i, j = 0;

    printf("Enter n number  \n");
    scanf("%d", &myNumN);
    printf("n i %d\n", myNumN);

    printf("Enter n number  \n");
    scanf("%d", &myNumM);
    printf("m is %d\n", myNumM);

    if (myNumN < myNumM)
    {
        printf("n should be >= m");
    }
    else
    {
        for (i = 0; i < myNumN; ++i)
        {
            if (counter == myNumM)
            {
                counter = 0;
                printf("\n");
            }
            printf("%d ", (1 + i));
            counter++;
        }

        printf("\n");

        // for (i = 0; i < myNumN; ++i)
        // {

        //     printf("%d ", (1 + i));
        //     if((i+1%myNumM)/myNumM ==0){
        //         printf("\n");
        //     }
        //     // for (j = 0; j < myNumN; j + myNumM)
        //     // {
        //     //     printf("\n");
        //     // }
        // }

        return 0;
    }
}
