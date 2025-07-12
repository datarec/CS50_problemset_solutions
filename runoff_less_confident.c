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

int verifyInput(int argc, char *userVote) 
{
    for (int i = 0; )

}

int castVotes(int argc, char *argv[]) 
{
    char voters[5];
    printf("Number of voters: ");
    fgets(voters, 5, stdin);
    int voteNo = atoi(voters);

    candidates candidate[argc-1];

    for (int i = 0; i < argc - 1; i++) 
    {
        candidate[i].votee = argv[i + 1];
    }
    /* 
    first make sure we're doing as many votes as there is candidates 
    then make sure you're doing as many votes as voteNo
    */

    // ask for input convert it to an integer then put it inside of the struct.
    for (int i = 0; argc - 1 > i; i++) 
    {
        for (int i = 0; i < voteNo; i++) 
        {
            char userVote[20];
            printf("Rank %d: ", i + 1);
            fgets(userVote, 20, stdin);
            verifyInput(argc, userVote);
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
    castVotes(argc, argv);
    return 0;
}
