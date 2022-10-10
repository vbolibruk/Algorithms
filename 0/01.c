// 2. Винести функцію розв'язування квадратного рівняння в окремий файл. Винести вивід розв'язку квадратного рівняння в окрему функцію.

// to build and run
// gcc -Wall -c 01.c && gcc -Wall -c functions.c &&  gcc -o  testprogram functions.o 01.o  && ./testprogra
#include <stdio.h>
#include "functions.h"

int main(void)
{
   double *p;
   printf("Program starts \n");
   p = solveEq(2, 3, 5);
   // if (p[0] &&  p[1])
   // {
      printf("First root = %f\n", p[0]);
      printf("Second root = %f\n", p[1]);
   // }
   return 0;
}
