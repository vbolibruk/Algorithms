// 1. Написати програму яка виводить повідомлення на екран чи є введене ціле число парне чи непарне 
#include <stdio.h>
#include <math.h>


int main(void)
{
   int myNum;
   printf("Type an integer number \n");
   scanf("%d", &myNum);

    if (myNum % 2 == 0)
        printf("Your number is  even \n");
    else
        printf("Your number is  odd \n");
        
   return 0;
}

