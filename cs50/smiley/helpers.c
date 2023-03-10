#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    RGBTRIPLE pixel = image[0][0];

    RGBTRIPLE color;
    color.rgbtBlue = 0xAB;
    color.rgbtGreen = 0xBA;
    color.rgbtRed = 0x90;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtBlue == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtRed == 0)
            {
               image[i][j] = color;
            }
        }
    }
}
