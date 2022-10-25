// 3. Написати програму, яка розкладає задане число на прості множники. Наприклад: 140: 2*2*5*7
#include <stdio.h>
#include <stdbool.h>
int commonDiv(int a, int b);
bool isPrime(int n);
int main() {
        SDL_Init(SDL_INIT_VIDEO);
        return 0;
    }


int main()
{
    int firstN, secondN, tempStor, i;

    printf("Enter 1st num \n");
    scanf("%d", &firstN);

    printf("Enter 2nd num \n");
    scanf("%d", &secondN);

    // make sure firstN  always big one
    if (secondN > firstN)
    {
        tempStor = secondN;
        firstN = secondN;
        secondN = tempStor;
    }
    if(isPrime(35437)){
         printf("number is prime!");
    }else {

    }
    // i = commonDiv(firstN,secondN);
    printf("Greates common div num %d \n", i);
    return 0;
}

int commonDiv(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return commonDiv(b, a % b);
    }
}


bool isPrime(int n)
{
    int counter = 0;
    // Corner case
    if (n <= 1){
        return false;
    }
        
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            counter++;
            break;
        }
    }
    if(counter == 0) 
        return true;
    return false;
}

