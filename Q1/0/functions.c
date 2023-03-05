// 2. Винести функцію розв'язування квадратного рівняння в окремий файл. Винести вивід розв'язку квадратного рівняння в окрему функцію.
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double *solveEq( double a , double b  , double c )
{
   // double a = 2;
   // double b = 3;
   // double c = -5;
   static double answersArr[2];
   double x;
   if ((b * b - 4 * a * c) >= 0)
   {
      x = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
      answersArr[0] = x;
      x = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
      answersArr[1] = x;
   }
   else
   {
      printf("D is less 0,  no real roots  \n");
   }      
   return answersArr;
}