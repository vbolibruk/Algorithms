// 6. Написати програму, яка виводить на екран числа від 1 до n, які не діляться націло на 3 та на 7. Також програма повинна зупинитися при виводі кореня з n, якщо це ціле число. Використати break та continue.

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int main(void)
{
    int myNum, i;
    double root;
    double int_part;
    double frac_part;

    bool myNumRootisWhole;

    printf("Enter number  \n");
    scanf("%d", &myNum);
    printf("Num is, %d\n", myNum);

    

    root = sqrt(myNum);
    frac_part  = modf(root, &int_part);
    if (frac_part == 0.0) {
        myNumRootisWhole = true;
    }
    

    printf("root is, %lf \n", root);
    printf("myNumRootisWhole %s\n", myNumRootisWhole ? "true" : "false");
    // one iterator
    for (i = 0; i <= myNum; ++i)
    {
        if(i==0){
            continue;
        }
        
        if ((i == int_part) && myNumRootisWhole)
        {
            printf("Perfect square %d found\n", i);
            break;
        }
       
        if (((i % 3) != 0) && ((i % 7) != 0))
        {
            printf("Cannot divide i on 3 or 7 without reminder , number is  %d \n", i);
        }


    }

    return 0;
}
