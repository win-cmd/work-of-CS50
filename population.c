//population.c
//This is a lab work of week 1.
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start = 0;
    int end = 0;
    do
    {
        start = get_int("Strat size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int n = start;
    int year = 0;
    while (n < end)
    {
        int birth = n / 3;
        int death = n / 4;
        n = n + birth - death;
        year++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", year);
}
