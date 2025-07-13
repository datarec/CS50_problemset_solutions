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

int verifyInput(char *argv[], char *userVote, int argc) 
{
    for (int i = 0; i < argc; i++) 
    {
        if (strcmp(argv[i], userVote) != 0) 
        {
            printf("Invalid vote.\n");
            return 1;
        }
    }

}

int castVotes(int argc, char *argv[]) 
{
    char voters[5];
    printf("Number of voters: ");
    fgets(voters, 5, stdin);
    int voteNo = atoi(voters);

    candidates candidate[argc];

    for (int i = 0; i < argc; i++) 
    {
        candidate[i].votee = argv[i + 1];
    }
    for (int i = 0; argc > i; i++) 
    {
        for (int i = 0; i < voteNo; i++) 
        {
            char userVote[20];
            printf("Rank %d: ", i + 1);
            fgets(userVote, 20, stdin);
            if (verifyInput(argv, userVote, argc) == 1) 
            {
                return 1;
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[])  
{
    if (argc < 2) 
    {  
        printf("Usage: ./runoff [candidate ...]\n");
        return 1;
    }
    else if (castVotes(argc-1, argv) == 1) 
    {
        return 1;
    }

}
