#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h += 1)
    {
        for (int w = 0; w < width; w += 1)
        {
            int grey = round((image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3.0);
            image[h][w].rgbtRed = grey;
            image[h][w].rgbtGreen = grey;
            image[h][w].rgbtBlue = grey;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h += 1)
    {
        for (int w = 0; w < width; w += 1)
        {
            // Store the original RGB values
            int originalRed = image[h][w].rgbtRed;
            int originalGreen = image[h][w].rgbtGreen;
            int originalBlue = image[h][w].rgbtBlue;

            // Calculate the red sepia value
            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            if (sepiaRed >= 255)
            {
                image[h][w].rgbtRed = 255;
            }
            else
            {
                image[h][w].rgbtRed = sepiaRed;
            }

            // Calculate the green sepia value
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            if (sepiaGreen >= 255)
            {
                image[h][w].rgbtGreen = 255;
            }
            else
            {
                image[h][w].rgbtGreen = sepiaGreen;
            }

            // Calculate the blue sepia value
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
            if (sepiaBlue >= 255)
            {
                image[h][w].rgbtBlue = 255;
            }
            else
            {
                image[h][w].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h += 1)
    {
        for (int w = 0; w < width / 2; w += 1)
        {
            // Store the original RGB values
            int storeRed = image[h][w].rgbtRed;
            int storeGreen = image[h][w].rgbtGreen;
            int storeBlue = image[h][w].rgbtBlue;

            // Copy the right pixel to the left pixel
            image[h][w].rgbtRed = image[h][width - w - 1].rgbtRed;
            image[h][w].rgbtGreen = image[h][width - w - 1].rgbtGreen;
            image[h][w].rgbtBlue = image[h][width - w - 1].rgbtBlue;

            // Copy the left pixel to the right pixel
            image[h][width - w - 1].rgbtRed = storeRed;
            image[h][width - w - 1].rgbtGreen = storeGreen;
            image[h][width - w - 1].rgbtBlue = storeBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the image
    RGBTRIPLE copy[height][width];
    for (int h = 0; h < height; h += 1)
    {
        for (int w = 0; w < width; w += 1)
        {
            copy[h][w].rgbtRed = image[h][w].rgbtRed;
            copy[h][w].rgbtGreen = image[h][w].rgbtGreen;
            copy[h][w].rgbtBlue = image[h][w].rgbtBlue;
        }
    }
    for (int h = 0; h < height; h += 1)
    {
        for (int w = 0; w < width; w += 1)
        {
            // Store the RGB value of the blur
            int red;
            int green;
            int blue;

            // Pixel at the top left corner
            if (h == 0 && w == 0)
            {
                red = round((copy[h][w].rgbtRed + copy[h][w + 1].rgbtRed +
                             copy[h + 1][w].rgbtRed + copy[h + 1][w + 1].rgbtRed) / 4.0);
                green = round((copy[h][w].rgbtGreen + copy[h][w + 1].rgbtGreen +
                               copy[h + 1][w].rgbtGreen + copy[h + 1][w + 1].rgbtGreen) / 4.0);
                blue = round((copy[h][w].rgbtBlue + copy[h][w + 1].rgbtBlue +
                              copy[h + 1][w].rgbtBlue + copy[h + 1][w + 1].rgbtBlue) / 4.0);
            }

            // Pixel at the top right corner
            else if (h == 0 && w == width - 1)
            {
                red = round((copy[h][w].rgbtRed + copy[h][w - 1].rgbtRed +
                             copy[h + 1][w].rgbtRed + copy[h + 1][w - 1].rgbtRed) / 4.0);
                green = round((copy[h][w].rgbtGreen + copy[h][w - 1].rgbtGreen +
                               copy[h + 1][w].rgbtGreen + copy[h + 1][w - 1].rgbtGreen) / 4.0);
                blue = round((copy[h][w].rgbtBlue + copy[h][w - 1].rgbtBlue +
                              copy[h + 1][w].rgbtBlue + copy[h + 1][w - 1].rgbtBlue) / 4.0);
            }

            // Pixel at the bottom left corner
            else if (h == height - 1 && w == 0)
            {
                red = round((copy[h][w].rgbtRed + copy[h][w + 1].rgbtRed +
                             copy[h - 1][w].rgbtRed + copy[h - 1][w + 1].rgbtRed) / 4.0);
                green = round((copy[h][w].rgbtGreen + copy[h][w + 1].rgbtGreen +
                               copy[h - 1][w].rgbtGreen + copy[h - 1][w + 1].rgbtGreen) / 4.0);
                blue = round((copy[h][w].rgbtBlue + copy[h][w + 1].rgbtBlue +
                              copy[h - 1][w].rgbtBlue + copy[h - 1][w + 1].rgbtBlue) / 4.0);
            }

            // Pixel at the bottom right corner
            else if (h == height - 1 && w == width - 1)
            {
                red = round((copy[h][w].rgbtRed + copy[h][w - 1].rgbtRed +
                             copy[h - 1][w].rgbtRed + copy[h - 1][w - 1].rgbtRed) / 4.0);
                green = round((copy[h][w].rgbtGreen + copy[h][w - 1].rgbtGreen +
                               copy[h - 1][w].rgbtGreen + copy[h - 1][w - 1].rgbtGreen) / 4.0);
                blue = round((copy[h][w].rgbtBlue + copy[h][w - 1].rgbtBlue +
                              copy[h - 1][w].rgbtBlue + copy[h - 1][w - 1].rgbtBlue) / 4.0);
            }

            // Pixel at the top edge
            else if (h == 0)
            {
                red = round((copy[h][w].rgbtRed + copy[h][w - 1].rgbtRed + copy[h][w + 1].rgbtRed +
                             copy[h + 1][w - 1].rgbtRed + copy[h + 1][w + 1].rgbtRed + copy[h + 1][w].rgbtRed) / 6.0);
                green = round((copy[h][w].rgbtGreen + copy[h][w - 1].rgbtGreen + copy[h][w + 1].rgbtGreen +
                               copy[h + 1][w - 1].rgbtGreen + copy[h + 1][w + 1].rgbtGreen + copy[h + 1][w].rgbtGreen) / 6.0);
                blue = round((copy[h][w].rgbtBlue + copy[h][w - 1].rgbtBlue + copy[h][w + 1].rgbtBlue +
                              copy[h + 1][w - 1].rgbtBlue + copy[h + 1][w + 1].rgbtBlue + copy[h + 1][w].rgbtBlue) / 6.0);
            }

            // Pixel at the bottom edge
            else if (h == height - 1)
            {
                red = round((copy[h][w].rgbtRed + copy[h][w - 1].rgbtRed + copy[h][w + 1].rgbtRed +
                             copy[h - 1][w - 1].rgbtRed + copy[h - 1][w + 1].rgbtRed + copy[h - 1][w].rgbtRed) / 6.0);
                green = round((copy[h][w].rgbtGreen + copy[h][w - 1].rgbtGreen + copy[h][w + 1].rgbtGreen +
                               copy[h - 1][w - 1].rgbtGreen + copy[h - 1][w + 1].rgbtGreen + copy[h - 1][w].rgbtGreen) / 6.0);
                blue = round((copy[h][w].rgbtBlue + copy[h][w - 1].rgbtBlue + copy[h][w + 1].rgbtBlue +
                              copy[h - 1][w - 1].rgbtBlue + copy[h - 1][w + 1].rgbtBlue + copy[h - 1][w].rgbtBlue) / 6.0);
            }

            // Pixels at the left edge
            else if (w == 0)
            {
                red = round((copy[h][w].rgbtRed + copy[h - 1][w].rgbtRed + copy[h + 1][w].rgbtRed +
                             copy[h][w + 1].rgbtRed + copy[h - 1][w + 1].rgbtRed + copy[h + 1][w + 1].rgbtRed) / 6.0);
                green = round((copy[h][w].rgbtGreen + copy[h - 1][w].rgbtGreen + copy[h + 1][w].rgbtGreen +
                               copy[h][w + 1].rgbtGreen + copy[h - 1][w + 1].rgbtGreen + copy[h + 1][w + 1].rgbtGreen) / 6.0);
                blue = round((copy[h][w].rgbtBlue + copy[h - 1][w].rgbtBlue + copy[h + 1][w].rgbtBlue +
                              copy[h][w + 1].rgbtBlue + copy[h - 1][w + 1].rgbtBlue + copy[h + 1][w + 1].rgbtBlue) / 6.0);
            }

            // Pixels at the right edge
            else if (w == width - 1)
            {
                red = round((copy[h][w].rgbtRed + copy[h - 1][w].rgbtRed + copy[h + 1][w].rgbtRed +
                             copy[h][w - 1].rgbtRed + copy[h - 1][w - 1].rgbtRed + copy[h + 1][w - 1].rgbtRed) / 6.0);
                green = round((copy[h][w].rgbtGreen + copy[h - 1][w].rgbtGreen + copy[h + 1][w].rgbtGreen +
                               copy[h][w - 1].rgbtGreen + copy[h - 1][w - 1].rgbtGreen + copy[h + 1][w - 1].rgbtGreen) / 6.0);
                blue = round((copy[h][w].rgbtBlue + copy[h - 1][w].rgbtBlue + copy[h + 1][w].rgbtBlue +
                              copy[h][w - 1].rgbtBlue + copy[h - 1][w - 1].rgbtBlue + copy[h + 1][w - 1].rgbtBlue) / 6.0);
            }

            // The remaining pixels
            else
            {
                red = round((copy[h][w].rgbtRed + copy[h - 1][w].rgbtRed + copy[h + 1][w].rgbtRed +
                             copy[h][w + 1].rgbtRed + copy[h - 1][w + 1].rgbtRed + copy[h + 1][w + 1].rgbtRed +
                             copy[h][w - 1].rgbtRed + copy[h - 1][w - 1].rgbtRed + copy[h + 1][w - 1].rgbtRed) / 9.0);
                green = round((copy[h][w].rgbtGreen + copy[h - 1][w].rgbtGreen + copy[h + 1][w].rgbtGreen +
                               copy[h][w + 1].rgbtGreen + copy[h - 1][w + 1].rgbtGreen + copy[h + 1][w + 1].rgbtGreen +
                               copy[h][w - 1].rgbtGreen + copy[h - 1][w - 1].rgbtGreen + copy[h + 1][w - 1].rgbtGreen) / 9.0);
                blue = round((copy[h][w].rgbtBlue + copy[h - 1][w].rgbtBlue + copy[h + 1][w].rgbtBlue +
                              copy[h][w + 1].rgbtBlue + copy[h - 1][w + 1].rgbtBlue + copy[h + 1][w + 1].rgbtBlue +
                              copy[h][w - 1].rgbtBlue + copy[h - 1][w - 1].rgbtBlue + copy[h + 1][w - 1].rgbtBlue) / 9.0);
            }

            // Convert the pixels into blur
            image[h][w].rgbtRed = red;
            image[h][w].rgbtGreen = green;
            image[h][w].rgbtBlue = blue;
        }
    }
    return;
}