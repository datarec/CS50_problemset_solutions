// Problem Set 2.
// Simple Runoff variant, CS50.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  
{
    int votes;
    char *votee;
} candidates;

int cmpstr(char *argv, char *userVote)
{
    for (int i = 0; argv[i] != '\0'; i++) 
    {
        if (argv[i] != userVote[i]) 
        {
            return 1;
        }
    }
    return 0;
}

int verifyInput(char *argv[], char userVote[], int argc) 
{
    for (int i = 0; i < argc; i++) 
    {
        if (cmpstr(argv[i], userVote) == 0) 
        {
            return 0;
        }
    }
    return 1;
}

int castVotes(int argc, char *argv[]) 
{
    char voters[5];
    printf("Number of voters: ");
    fgets(voters, 5, stdin);
    int voteNo = atoi(voters);

    for (int i = 0; argc-1 > i; i++) 
    {
        for (int i = 0; i < voteNo; i++) 
        {
            char userVote[20];
            printf("Rank %d: ", i + 1);
            fgets(userVote, 20, stdin);
            if (verifyInput(argv, userVote, argc) == 1) 
            {
                printf("Invalid vote.");
                return 1;
            }
        }
    }
}

int main(int argc, char* argv[])  
{
    if (argc < 2) 
    {  
        printf("Usage: ./runoff [candidate ...]\n");
        return 1;
    }
    else if (castVotes(argc, argv) == 1) 
    {
        return 1;
    }
}
