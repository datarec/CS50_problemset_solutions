// Problem Set 1. 
// Harder problem, CS50. 

#include <stdio.h>
#include <ctype.h>

void getCardType(unsigned long long number2, short numCount) 
{
    int NUMCOUNT = numCount;
    while (numCount) 
    {
        if (numCount == 1) 
        {
            if (NUMCOUNT == 13 || NUMCOUNT == 14 
                || NUMCOUNT == 15 || NUMCOUNT == 16) 
            {
                if (number2 % 10 == 4) 
                {
                    if (NUMCOUNT == 13 || NUMCOUNT == 14 ||
                    NUMCOUNT == 15 || NUMCOUNT == 16) 
                    {
                        printf("VISA\n");
                    }
                }
            }
        }
        // else if statement for american express. 
        else if (numCount <= 2) 
        {
            int americanExpress[] = {4, 3, 7, 3};
            int mastercard[] = {1, 5, 2, 5, 3, 5, 4, 5 ,5, 5};
            if (NUMCOUNT == 15) 
            {
                if (number2 % 10 == americanExpress[2] || 
                    number2 % 10 == americanExpress[0]) 
                {
                    number2 /= 10;
                    if (number2 % 10 == americanExpress[3] ||
                        number2 % 10 == americanExpress[1]) 
                    {
                        printf("AMERICAN EXPRESS\n");
                    }      
                }
            }
            else if (NUMCOUNT == 16) 
            {
                for (int i = 0; i <= 10; i++) 
                {   
                    if (i % 2 == 0) 
                    {
                        if (number2 % 10 == mastercard[i]) 
                        {
                            number2 /= 10;
                            if (number2 % 10 == mastercard[1]) 
                            {
                                printf("MASTERCARD\n");
                            }
                        }
                    }
                }
            }
        }
        numCount--;
        number2 /= 10;
    } 
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
    int noletters = isdigit(number);
    do 
    {
        printf("Number: ");
        scanf("%llu", &number);
    }
    while (number < 1);
    multiplySecLast(number);
}
