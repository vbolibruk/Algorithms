// 4. Написати програму, яка динамічно виділяє пам'ять під структуру, зчитує її поля та виводить їх.

#include <stdio.h>
#include <stdlib.h>

struct course
{
    int marks;
    char subject[30];
};

int main()
{

    struct course *ptr;
    int noOfRecords;

    int  i;
    printf("Enter number of elements \n");
    scanf("%d", &noOfRecords);

    ptr = (struct course *)malloc(noOfRecords * sizeof(struct course));

    for (i = 0; i < noOfRecords; ++i)
    {
        printf("Enter subject and marks:\n");
        scanf("%s %d", (ptr + i)->subject, &(ptr + i)->marks);
    }
    printf("Displaying Information:\n");
    for (int i = 0; i < noOfRecords; ++i)
    {
        printf("%s\t%d\n", (ptr + i)->subject, (ptr + i)->marks);
    }

    free(ptr);
    return 0;
}