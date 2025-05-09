#include <stdio.h>
#include <stdlib.h>

int lCounter = 1;
int brickCount = 0;
int counter = 0;

void make_right(int brickCount) 
{
    if (brickCount != counter) 
    {
        while (brickCount != counter) 
        {
            counter++;
            printf("#");
            if (brickCount == counter) 
            { 
                printf("\n");
                counter = 0;
                break;
            }
        }
    }
}

void make_left(int bricks) 
{
  while (lCounter != bricks) 
  {
    if (brickCount != lCounter) 
    {
      printf("#");
      brickCount++;
    }
    else if (brickCount == lCounter) 
    {
      lCounter++;
      printf(" ");
      make_right(brickCount);
      brickCount = 0;
      return;
    }
  } 
}

void make_spaces(int bricks) 
{
  int spaces = bricks - 1;
  int rowsLeft = spaces;
  while (rowsLeft != 0) 
  {
    if (spaces != 0) 
    {
      printf(" ");
      spaces--;
    }
    else if (spaces == 0) 
    {
      make_left(bricks);
      rowsLeft--;
      spaces = rowsLeft;
      printf("\n");
    }
  }
}

int main()
{
  int nBricks = 0;
  do 
  {
    printf("Height: ");
    scanf("%d", &nBricks);
  }
  while (nBricks < 1);
  printf("\n"); 
  make_spaces(nBricks + 1);
}
