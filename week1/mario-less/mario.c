#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: "); //Stores the height of the pyramid
    }
    while (height <= 0 || height > 8);

    for (int i = 1; i <= height; i += 1)
    {
        //Print empty spaces
        for (int k = height - i; k > 0; k -= 1)
        {
            printf(" ");
        }
        // Print #
        for (int j = i; j > 0; j -= 1)
        {
            printf("#");
        }
        printf("\n"); //Print the next line
    }
}