// CS50 Cash problem, this is the easier variant.  

#include <stdio.h>

int getChange(int money) 
{   
    int coinCount;
    int coins[] = {25, 10, 5, 1};
    while (money != 0) 
    {
        for (int i = 0; i < sizeof(coins) / 4; i++) 
        {
            if (coins[i] <= money) 
            {
                money = money - coins[i];
                coinCount++;
            }
        }
    }
    printf("%d", coinCount);
}

int main() 
{
    int money;
    do 
    {
        printf("Change owed: ");
        scanf("%d", &money);
    }
    while (money < 1);
    getChange(money);
}
