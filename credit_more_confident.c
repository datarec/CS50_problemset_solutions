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
