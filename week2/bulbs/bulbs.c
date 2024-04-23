#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void decimal_to_binary(char text, int bit[]);
void print_bulb(int bit);

int main(void)
{
    // Stores the input text
    string text = get_string("Message: ");
    int length = strlen(text);
    int bit[length][BITS_IN_BYTE]; // Store the binary of each character

    // Find the binary for each character and print the line of bulbs
    for (int i = 0; i < length; i += 1)
    {
        decimal_to_binary(text[i], bit[i]);
        // Print the bulb for each binary
        for (int j = 0; j < BITS_IN_BYTE; j += 1)
        {
            print_bulb(bit[i][j]);
        }
        printf("\n");
    }
}

// Converts decimal to binary
void decimal_to_binary(char text, int bit[])
{
    for (int i = 7; i >= 0; i -= 1)
    {
        if (text % 2 == 0)
        {
            // Sets bit to 0 if there is no remainder
            bit[i] = 0;
            text /= 2;
        }
        else
        {
            // Sets bit to 1 if there is remainder
            bit[i] = 1;
            text /= 2;
        }
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
