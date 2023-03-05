// 5. Напишіть ітеративну та рекурсивну функції, які розраховують n-те число Фібоначчі

// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144

// 1 1
// 2 1
// 3 2
// 4 3

#include <stdio.h>

int customIter(int n);
int customRecursion(int n);

int main()
{

    int n = 10;
    int result1;
    int result2;

    result1 = customIter(n);
    result2 = customRecursion(n);

    printf("customIter is = %d  \n ", result1);
        printf("customRecursion is = %d  \n ", result2);

    return 0;
}
int customIter(n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    int firstNum = 1;
    int secondNum = 1;
    for (int i = 0; i < (n - 3); i++)
    {
        int temp = firstNum + secondNum;
        firstNum = secondNum;
        secondNum = temp;
    }

    return firstNum + secondNum;
}

//             3
//         2       1
//     1     0      return 1
// return 1 return 0  
int customRecursion(int n)
{
    if (n <= 1)
        return n;
    return customRecursion(n - 1) + customRecursion(n - 2);
}
