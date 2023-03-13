#include "helpers.h"
#include <math.h>

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
    RGBTRIPLE copy[height][width];

    // Copy the pixels from the original image to the copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Calculate the blur values for each pixel in the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red_sum = 0, green_sum = 0, blue_sum = 0;
            int count = 0;

            // Loop over the pixels in the box around the current pixel
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    // Only process pixels that are within the bounds of the image
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        red_sum += copy[k][l].rgbtRed;
                        green_sum += copy[k][l].rgbtGreen;
                        blue_sum += copy[k][l].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate the average color for the box and update the pixel in the original image
            image[i][j].rgbtRed = round((float) red_sum / count);
            image[i][j].rgbtGreen = round((float) green_sum / count);
            image[i][j].rgbtBlue = round((float) blue_sum / count);
        }
    }
}
