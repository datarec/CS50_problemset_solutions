#include <stdio.h>
#include <stdlib.h>

int counter = 1;
int brickCount = 0;

void make_bricks(int bricks) 
{
  while (counter != bricks) 
  {
    if (brickCount != counter) 
    {
      printf("#");
      brickCount++;
    }
    else if (brickCount == counter) 
    {
      counter++;
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
      make_bricks(bricks);
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
    printf("Enter height: ");
    scanf("%d", &nBricks);
  }
  while (nBricks < 1);
  printf("\n"); 
  make_spaces(nBricks + 1);
}
