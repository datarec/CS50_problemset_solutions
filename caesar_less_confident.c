// Problem set 2.
// Simple caesar variant, CS50.

#include <stdio.h>

int cypher_text(char* argv[]) 
{
	char plaintext[100];
	printf("plaintext: ");
	fgets(plaintext, 100, stdin);
	printf("cyphertext: ");
	for (int i = 0; plaintext[i] != '\0'; i++) 
	{
		printf("%c", plaintext[i] + 1);
	}
	printf("\n");
}

int main(int argc, char* argv[]) 
{
	char errormsg[20] = "Usage: ./caesar key";
	for (int i = 0; argv[1][i] != '\0'; i++) 
	{
		if (argc != 2) 
		{
			printf("%s\n", errormsg);
			return 1;
		}
		else if (argv[1][i] >= 'a' && argv[1][i] <= 'z') 
		{
			printf("%s\n",  errormsg);
			return 1;
		}
	}
	cypher_text(argv);
}
