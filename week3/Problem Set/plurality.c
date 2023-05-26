#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;//the number of candidates
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];//argv is used to receive the input(names of candidates).
        candidates[i].votes = 0;//inital variable
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (!strcmp(candidates[i].name, name))
        {
            //printf("%s",candidates[i].name);
            candidates[i].votes += 1;
            return true;
        }
        //printf("%s,%s,%d",name,candidates[i].name,name==candidates[i].name);
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int index[MAX];
    index[0] = 0;
    int j = 1;
    for (int i = 0; i < candidate_count - 1; i++)
    {
        if (candidates[i].votes < candidates[i + 1].votes)
        {
            index[0] = i + 1;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (i != index[0] && candidates[i].votes == candidates[index[0]].votes)
        {
            index[j] = i;
            j++;
        }
    }

    for (int i = 0; i < j; i++)
    {
        printf("%s\n", candidates[index[i]].name);
    }
    return;
}
