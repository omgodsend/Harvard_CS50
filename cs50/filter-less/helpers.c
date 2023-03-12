#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;

    RGBTRIPLE gs;
    gs.rgbtBlue = avg;
    gs.rgbtGreen = avg;
    gs.rgbtRed = avg;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           int avg = ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);

           image[i][j] = gs;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
