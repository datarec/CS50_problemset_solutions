#include <stdio.h>

int retLen(char* argv[]); 
int checkAlpha(char* argv[]);

int main(int argc, char* argv[])  
{
	if (argc != 2) 
	{
		printf("Usage: ./substitution key\n");
		return 1;
	}
	int length = retLen(argv);
	int isAlpha = checkAlpha(argv);
	if (length != 26 && isAlpha == 0) 
	{
		printf("Key must be alphabetical and 26 letters in length.\n");
		return 1;
	}
}

int checkAlpha(char* argv[]) 
{
	for (int i = argv[1][i] != '\0'; i++) 
	{
		
	}
}

int retLen(char* argv[]) 
{
	int i = 0;
	for (i; argv[1][i] != '\0';) 
	{
		i++;
	}
	return i;
}
