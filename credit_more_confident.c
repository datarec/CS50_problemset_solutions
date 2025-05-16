// program to check the valididy of a card

#include <stdio.h>

void getCardType(unsigned long long number2, short numCount) 
{
    // visa check
    if (numCount == 15) 
    {

    }
    else if (numCount == 16) 
    {

    }
    else if (numCount == )
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
        getCardType(number2, numCount);
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
                    evenSum = evenSum + (first + second);
                }
            }
            else if (cardNumDoubled > 0)
            {
                evenSum = evenSum + cardNumDoubled;
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
