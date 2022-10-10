// 1. Написати програму для розв'язання квадратного рівняння. Алгоритм розв'язування помістити в окрему функцію (функція ніяк не повинна взаємодіяти з користувачем)
#include <stdio.h>
#include <math.h>

void solveEq (void); 

int main(void)
{

   printf("Program starts \n");
   solveEq();
   return 0;
}

void solveEq(void)
{
   double a = 2;
   double b = 3;
   double c = -5;
   double x;
   if ((b * b - 4 * a * c) >= 0)
   {
      x = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
      printf("First root = %f\n", x);
      x = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
      printf("Second root = %f\n", x);
   }
   else
   {
      printf("D is less 0,  no real roots  \n");
   }
}