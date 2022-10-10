// 2. Винести функцію розв'язування квадратного рівняння в окремий файл. Винести вивід розв'язку квадратного рівняння в окрему функцію.

// to build and run
// gcc -Wall -c 02.c && gcc -Wall -c functions.c &&  gcc -o  testprogram2 functions.o 02.o  && ./testprogram2
#include <stdio.h>
#include "functions.h"
#include <assert.h>
int main(void)
{
   double *p;
   printf("Program starts \n");
   p = solveEq(2, 3, 5);
   assert((p[0] +p[1]) == 0.000000);

   p = solveEq(2, 3, -5);
   assert(p[0] == 1.000000);
   assert(p[1] == -2.500000);

   return 0;
}
