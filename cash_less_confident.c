#include <stdio.h>
#include <stdlib.h>

int money = 0;

int getChange(int money) 
{   
    int coinCount;
    while (money != 0) 
    {
        if (25 <= money) 
        {
            money = money - 25;
            coinCount++;
        }
        else if (10 <= money) 
        {
            money = money - 10;
            coinCount++;
        }
        else if (5 <= money) 
        {
            money = money - 5;
            coinCount++;
        }
        else if (1 <= money) 
        {
            money = money - 1;
            coinCount++;
        }
    }
    printf("%d", coinCount);
}

int main() 
{
    do 
    {
        printf("Change owed: ");
        scanf("%d", &money);
    }
    while (money < 1);
    getChange(money);
}
