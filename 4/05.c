// 5. Написати інтерактивну програму, яка вгадує задумане число користувачем (в діапазоні від 0 до 100) за мінімальну кількість спроб

#include <stdio.h>
#include <stdbool.h>
int guessNumber(int leftIndex, int rightIndex);
int main()
{

    int n = 99;

    int leftIndex = 0;
    int rightIndex = n;
    int m;

    bool aiFoundValue = false;
    int inputFromUserQuestion1 = 0;
    int inputFromUserQuestion2 = 0;

    int tries = 0;
    int number = 50;

    printf("Get number from 0 to 100  \n");
    while (!aiFoundValue || tries < 8)
    {
        printf("Your number  is %d , Is it true? type 1 - for yes or 0 for no   \n", number);

        scanf(" %d", &inputFromUserQuestion1);
        if (inputFromUserQuestion1 == 1)
        {
            aiFoundValue = true;
            break;
        }

        printf("Does your number bigger or lower? type 1 - for bigger or 0 for lower  \n");
        scanf(" %d", &inputFromUserQuestion2);
        if (inputFromUserQuestion2 == 0)
        {
            rightIndex = number - 1;
            m = guessNumber(leftIndex,rightIndex);
            number = m+ 1;
        }
        if (inputFromUserQuestion2 == 1)
        {
            leftIndex = number - 1;
            m = guessNumber(leftIndex,rightIndex);
            number = m+ 1;
        }
        tries++;
    }
    printf("AI spent %d tries to guess number   \n", tries);
    return 0;
}

guessNumber(int leftIndex, int rightIndex)
{   
    int m;

    if (leftIndex <= rightIndex)
    {
        m = (rightIndex + leftIndex) / 2;
    }
    return m;
}