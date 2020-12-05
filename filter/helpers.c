#include "helpers.h"
#include <cs50.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            //getting values of each color
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            //getting average
            float average = round(red + blue + green) / 3;
            average = round(average);

            //implementing average to make rgb values equal
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            //getting values of each color
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            //computing for sepia code
            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);


            //checking first if each value is greater than 255
            //then, implementing average to make rgb values equal

            //sepia red
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            //sepia blue
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }

            //sepia green
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //temporary array placeholder for swapping
    int rev_rgb[3];
    for (int i = 0; i < height; i++)
    {
        //half of the width only to invert, else, if full width it will just go back to original
        for (int j = 0; j < width / 2; j++)
        {
            rev_rgb[0] = image[i][j].rgbtRed;
            rev_rgb[1] = image[i][j].rgbtBlue;
            rev_rgb[2] = image[i][j].rgbtGreen;

            //swapping pixels with the opposite side of the pic
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;

            image[i][width - j - 1].rgbtRed = rev_rgb[0];
            image[i][width - j - 1].rgbtBlue = rev_rgb[1];
            image[i][width - j - 1].rgbtGreen = rev_rgb[2];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //creating temporary storage for RGB colors
    RGBTRIPLE store[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blurRed = 0;
            int blurBlue = 0;
            int blurGreen = 0;
            float counter = 0.00;

            //summing to the outisde values of pixel

            for (int x = -1; x < 2; x++)
            {
                //checking neighbors
                if (i + x < 0 | i + x > height - 1)
                {
                    continue;
                }

                for (int y = -1; y < 2; y++)
                {
                    if (j + y < 0 | j + y > width - 1)
                    {
                        continue;
                    }

                    blurRed += image[i + x][j + y].rgbtRed;
                    blurBlue += image[i + x][j + y].rgbtBlue;
                    blurGreen += image[i + x][j + y].rgbtGreen;
                    counter ++;

                }
            }

            //averaging for more blur effect
            store[i][j].rgbtRed = round(blurRed / counter);
            store[i][j].rgbtBlue = round(blurBlue / counter);
            store[i][j].rgbtGreen = round(blurGreen / counter);

        }
    }

    //copying values from temporary storage
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = store[i][j].rgbtRed;
            image[i][j].rgbtBlue = store[i][j].rgbtBlue;
            image[i][j].rgbtGreen = store[i][j].rgbtGreen;
        }
    }
}
