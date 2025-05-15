// Problem Set 1.
// Harder Credit variant, CS50. 

#include <stdio.h>

void getCardType(unsigned long long number2) 
{
    
}

void addSumOfExpression(unsigned long long number1, short evenSum) 
{
    short numCount; 
    unsigned long long number2 = number1;
    int oddSum = 0;
    while (number1) 
    {
        numCount++;
        if (numCount % 2 == 1 && number1 % 10 > 0) 
        {
            oddSum += number1 % 10;
        }
        number1 /= 10;
    }
    short finalSum = evenSum + oddSum;
    if (finalSum % 10 == 0) 
    {
        getCardType(number2);
    }
    else if (finalSum % 10 != 0) 
    {
        printf("INVALID\n");
    } 
}

void multiplySecLast(unsigned long long number)
{
    unsigned long long number1 = number;
    int numCount;
    short evenSum;
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
                    evenSum += first + second;
                }
            }
            else 
            { 
                evenSum =+ cardNumDoubled;
            }
        }
        number /= 10;
    }
    addSumOfExpression(number1, evenSum);
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
    multiplySecLast(number);
}

// Confused about how to Analyse each digit?

/* 
1. Divide by 10 to remove a digit from your input variable, for this use a while loop.
2. as you divide number (your input variable), will eventually divide itself to zero, meaning
the while loop will automatically break out because 0 cannot be a true expression. 
*/
