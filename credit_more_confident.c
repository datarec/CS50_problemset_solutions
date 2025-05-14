// Problem Set 1.
// Harder Credit variant, CS50. 

#include <stdio.h>

void checkValidity(unsigned long long number)
{
    int numCount;
    int finalSum;
    while (number)
    {
        numCount++;
        if (numCount % 2 == 0) 
        {
            short int cardNumDoubled = (number % 10) * 2;
            if (cardNumDoubled > 9) 
            {
                while (cardNumDoubled) 
                {
                    int first = cardNumDoubled % 10;
                    cardNumDoubled /= 10;
                    int second = cardNumDoubled % 10;
                    cardNumDoubled /= 10;
                    finalSum += first + second;
                    //printf("%d\n", first + second); 
                }
            }
            else 
            { 
                //printf("%d\n", cardNumDoubled); 
                finalSum += cardNumDoubled;
            }
        }
        number /= 10;
    }
    printf("SUM: %d", finalSum);
}

int main()
{
    unsigned long long number;
    do 
    {
        printf("Number: ");
        scanf("%llu", &number);
    }
    while (number < 1);
    checkValidity(number);
}

// Confused about how to Analyse each digit?

/* 
1. Divide by 10 to remove a digit from your input variable, for this use a while loop.
2. as you divide number (your input variable), will eventually divide itself to zero, meaning
the while loop will automatically break out because 0 cannot be a true expression. 
*/
