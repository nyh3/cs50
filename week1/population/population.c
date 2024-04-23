#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("What's the start size? "); //Stores the start size
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("What's the end size? "); //Stores the end size
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int year = 0;
    int born;
    int pass_away;
    int change;
    for (int left = start; left < end; left += change)
    {
        born = left / 3; //Calculate the llama born that year
        pass_away = left / 4; //Calculate the llama that pass away that year
        change = born - pass_away; //Calculate total change in population for that year
        year += 1;
    }
    // TODO: Print number of years
    printf("Years: %i\n", year);
}
