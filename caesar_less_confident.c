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
		printf("%c", plaintext[i] + 13);
	}
	printf("\n");
}

int main(int argc, char* argv[]) 
{
	if (argc != 2) 
	{
		printf("Usage: ./caesar key\n");
		return 1;
	}
	cypher_text(argv);
}
