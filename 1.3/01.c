// 2. Написати програму, яка обчислює суму елементів масиву не використовуючи оператор отримання елементу масиву [?]
// #include <stdio.h>
// #include <math.h>


#include <stdio.h>
int main() {

  int i, x[6] = {1,2,3,4,5,6}, sum = 0;

  printf("Enter 6 numbers: ");

  for(i = 0; i < 6; ++i) {
  // Equivalent to scanf("%d", &x[i]);
  //  scanf("%d", x+i);

  // Equivalent to sum += x[i]
  sum += *(x+i);
  }

  printf("Sum = %d", sum);

  return 0;
}