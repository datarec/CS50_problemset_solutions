// Problem set 2.
// Simple caesar variant, CS50.

#include <stdio.h>
#include <stdlib.h>

int cypher_text(char* argv[]) 
{
	int key = atoi(argv[1]);
	char plaintext[100];
	printf("plaintext: ");
	fgets(plaintext, 100, stdin);
	printf("cyphertext: ");
	for (int i = 0; plaintext[i] != '\0'; i++) 
	{
		if (plaintext[i] + key > 'z')
		{
			printf("%c", (plaintext[i] + key - 'z') + 'a' - 1);
		}
		else if (plaintext[i] < 'A' || plaintext[i] < 'a')  
		{
			printf("%c", plaintext[i]);
		}
		else 
		{
			printf("%c", plaintext[i] + key);
		}
	}
	printf("\n");
}

int main(int argc, char* argv[]) 
{
	char errormsg[20] = "Usage: ./caesar key";
	if (argc != 2) 
	{
		printf("%s\n", errormsg);
		return 1;
	}	
	for (int i = 0; argv[1][i] != '\0'; i++) 
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z') 
		{
			printf("%s\n",  errormsg);
			return 1;
		}
	}
	cypher_text(argv);
}
