#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    RGBTRIPLE pixel = image[0][0]

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtBlue == pixel.rgbtBlue[0] && image[i][j].rgbtGreen == pixel.rgbtGreen[0] && image[i][j].rgbtRed == pixel.rgbtRed[0])
            {
                pixel.rgbtBlue[10];
                pixel.rgbtGreen[10];
                pixel.rgbtRed[10];
            }
        }
    }
return void;
}
