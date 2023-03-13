#include "helpers.h"
#include <math.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

           image[i][j].rgbtBlue = avg;
           image[i][j].rgbtGreen = avg;
           image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void check_white(int *color);
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            int sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            int sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            check_white(&sepiaRed);
            check_white(&sepiaGreen);
            check_white(&sepiaBlue);

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
return;
}
//./filter -b images/yard.bmp out.bmp
void check_white(int *color)
{
    if (*color > 0xFF)
    {
        *color = 0xFF;
    }
}


// Reflect image horizontally
void swap(BYTE *a, BYTE *b);
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int k = width - 1 - j;
            swap(&image[i][j].rgbtBlue, &image[i][k].rgbtBlue);
            swap(&image[i][j].rgbtGreen, &image[i][k].rgbtGreen);
            swap(&image[i][j].rgbtRed, &image[i][k].rgbtRed);
        }
    }
    return;
}



void swap(BYTE *a, BYTE *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     // Create a copy of the image to read from and write to
    RGBTRIPLE copy[height][width];
    memcpy(copy, image, sizeof(copy));

    // Loop over every pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int red = 0, green = 0, blue = 0;

            // Loop over every pixel in a 3x3 box centered on the current pixel
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    // Check if the current pixel is within the bounds of the image
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width)
                    {
                        // Add the color values to the running totals and increment the count
                        red += copy[i + k][j + l].rgbtRed;
                        green += copy[i + k][j + l].rgbtGreen;
                        blue += copy[i + k][j + l].rgbtBlue;
                        count++;
                    }
                }
            }

            // Set the color of the current pixel to the average of the surrounding pixels
            image[i][j].rgbtRed = round((float) red / count);
            image[i][j].rgbtGreen = round((float) green / count);
            image[i][j].rgbtBlue = round((float) blue / count);
        }
    }
}
