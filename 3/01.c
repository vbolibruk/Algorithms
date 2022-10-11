// "2. Алгоритм Евкліда (Euclidean algorithm)
// Написати функцію, яка знаходить найбільший спільний дільник двох чисел за алгоритмом Евкліда"
#include <stdio.h>


int main()
{
    int firstN , secondN , tempStor,  i, commonDiv = 1;

    printf("Enter 1st num \n");
    scanf("%d", &firstN);

    printf("Enter 2nd num \n");
    scanf("%d", &secondN);


    // make sure firstN  always big one
    if(secondN>firstN){
        tempStor = secondN;
        firstN = secondN;
        secondN = tempStor;
    }



    for (i = secondN; i > 1; --i)
    {
            if((secondN % i == 0) && (firstN % i == 0)){
                    commonDiv = i;
                    break;
                    
            }
    }

    printf("Greates common div num %d \n",i);
    return 0;
}

