#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h += 1)
    {
        for (int w = 0; w < height; w += 1)
        {
            // Check if the pixels are black
            if (image[h][w].rgbtRed == 0x00 && image[h][w].rgbtGreen == 0x00 && image[h][w].rgbtBlue == 0x00)
            {
                // Turns the black pixels purple
                image[h][w].rgbtRed = 0xff;
                image[h][w].rgbtBlue = 0xff;
            }
        }
    }
}
