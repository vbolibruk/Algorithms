// 2. Написати функцію, яка приймає 4 цілочисельні аргументи та повертає максимальний використовуючи мінімальну кількість порівнянь.
#include <stdio.h>
#include <math.h>


int main(void)
{
   int intArr[4];
   int i, number;
   printf("Type 1st integer numbers \n");
   scanf("%d", &number);
   intArr[0] = number;

   printf("Type 2nd integer numbers \n");
   scanf("%d", &number);
   intArr[1] = number;

   printf("Type 3d integer numbers \n");
   scanf("%d", &number);
   intArr[2] = number;

   printf("Type 4th integer numbers \n");
   scanf("%d", &number);
   intArr[3] = number;



   for (i = 0; i < 4; i++) {
  
        if(intArr[i]> number) {
            number = intArr[i];
        };
    };
    printf("Biggest number is %d ",number);
        
   return 0;
}

