// 1. Написати програму для розв'язання квадратного рівняння. Алгоритм розв'язування помістити в окрему функцію (функція ніяк не повинна взаємодіяти з користувачем)
#include <stdio.h>
#include <math.h>

int * swap(int a , int b); 

int main(void)
{
   int *p;
   p = swap(1,2);
   printf("swapped =  %d,  %d \n", p[0], p[1]);
   return 0;
}

int *swap( int a , int b   )
{

   static int answersArr[2];

   answersArr[0] = b;
   answersArr[1] = a;
   return answersArr;
}