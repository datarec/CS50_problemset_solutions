#include <stdio.h>

int retLen(char* argv[]); 
int checkAlpha(char* argv[]);
int substitution(char* argv[]);

int main(int argc, char* argv[])  
{
	if (argc != 2) 
	{
		printf("Usage: ./substitution key\n");
		return 1;
	}
	int length = retLen(argv);
	int isAlpha = checkAlpha(argv);
	if (length != 26 || isAlpha == 1) 
	{
		printf("Usage: ./substitution key (MAX-MIN 26 letters)\n");
		return 1;
	}
	substitution(argv);
}

int substitution(char* argv[]) 
{
	char plaintext[100];
	printf("plaintext: ");
	fgets(plaintext, 100, stdin);
	for (int i = 0; plaintext[i] != '\0'; i++) 
	{
		
		printf("%c", argv[1][(plaintext[i] - 'a')]);
	}
	printf("\n");
}

int checkAlpha(char* argv[]) 
{ 
	for (int i = 0; argv[1][i] != '\0'; i++) 
	{
		if (argv[1][i] < 'A' || argv[1][i] > 'Z' && argv[1][i] < 'a') 
		{
			return 1;
		}
		else if (argv[1][i] > 'z') 
		{
			return 1;
		}
	}
	return 0;
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
