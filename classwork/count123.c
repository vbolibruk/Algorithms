#include <stdio.h>
#include <stdlib.h>

#define N 6

int main(void)
{
    int arrayToSort[N + 1] = {0, 1, 2, 0, 1, 2};
    int sorted[N + 1] = {2,2,2,2,2,2};
    int zeroes = 0;
    int ones = 0;
    int twos = 0;

    for (int i = 0; i < N; i++)
    {
        if (arrayToSort[i] == 0)
        {
            zeroes++;
        }
        if (arrayToSort[i] == 1)
        {
            ones++;
        }


    }

   for(int loop = 0; loop < N; loop++){
           if(zeroes > 0){
            sorted[loop] = 0;
            zeroes--;
        }

        if(ones > 0){
            sorted[loop] = 1;
            ones--;
        }

      printf("%d ", sorted[loop]);

   }
    return 0;
}
