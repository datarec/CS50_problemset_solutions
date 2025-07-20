// Problem Set 2.
// Simple Runoff variant, CS50.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate
{
    int votes;
    char *votee;
};

int cmpstr(char args[], char *userVote)
{
    for (int i = 0; args[i] != '\0'; i++) 
    {
        if (args[i] != userVote[i]) 
        {
            return 1;
        }
    }
    return 0;
}

int verifyInput(char *args[], char userVote[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        if (!cmpstr(args[i], userVote)) 
        {
            return 0;
        }
    }
    return 1;
}

int castVotes(int size, char *args[]) 
{
    struct candidate candidates[size];
    char voters[5];
    printf("Number of voters: ");
    fgets(voters, 5, stdin);
    int voteNo = atoi(voters);
    for (int i = 0; size-1 > i; i++) 
    {
        candidates[i].votee = args[i+1];
        for (int i = 0; i < voteNo; i++) 
        {
            char userVote[20];
            printf("Rank %d: ", i + 1);
            fgets(userVote, 20, stdin);
            if (verifyInput(args, userVote, size)) 
            {
                printf("Invalid vote.");
                return 1;
            }
        }
        printf("\n");
    }
    return 0;
}

int main(int argc, char* argv[])  
{
    if (argc < 3) 
    {  
        printf("Usage: ./runoff [candidate ...]\n");
        return 1;
    }
    else if (castVotes(argc, argv)) 
    {
        return 1;
    }
}
