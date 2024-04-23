#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover infile\n");
        return 1;
    }

    // Open memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    // Set pointer to img to NULL
    FILE *img = NULL;

    // Create an array of 512 elements to store 512 bytes from the memory card
    BYTE buffer[BLOCK_SIZE];

    // Count amount of jpeg files found
    int jpeg = 0;

    // String to store filename
    char filename[8];

    // Read memory card until the end of file
    while (fread(buffer, sizeof(BYTE) * BLOCK_SIZE, 1, card) == 1)
    {
        // Check if jpeg is found
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
        {
            // Close img if jpeg is not the first image.
            if (jpeg != 0)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", jpeg);
            jpeg += 1;

            // Open a new img for writing a new found jpeg
            img = fopen(filename, "w");
        }
        // Keep writing to jpeg file if new jpeg is not found
        if (img != NULL)
        {
            fwrite(buffer, sizeof(BYTE) * BLOCK_SIZE, 1, img);
        }
    }
    // Close last opened img
    fclose(img);
    // Close memory card
    fclose(card);
    return 0;
}