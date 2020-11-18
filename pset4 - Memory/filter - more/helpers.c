#include "math.h"
#include "stdlib.h"
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loops through each Column (Height)
    for (int i = 0; i < width; i++)
    {
        // Loops through each Row (Width)
        for (int j = 0; j < width; j++)
        {
            // Gets the average value of all 3 colours
            float avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.000);
            // Updates each colour with the average value
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    // Loops through each Column (Height)
    for (int i = 0, x = height; i < x; i++)
    {
        // Loops through each Row (Width)
        for (int j = 0, y = width - 1; j < y; j++, y--)
        {
            // Copying left side
            temp[0] = image[i][j].rgbtRed;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtBlue;
            // Moving right side to left
            image[i][j].rgbtRed = image[i][y].rgbtRed;
            image[i][j].rgbtGreen = image[i][y].rgbtGreen;
            image[i][j].rgbtBlue = image[i][y].rgbtBlue;
            // Moving left side to right
            image[i][y].rgbtRed = temp[0];
            image[i][y].rgbtGreen = temp[1];
            image[i][y].rgbtBlue = temp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Creating a temporary copy of the image for creating the blur value
    RGBTRIPLE temp[height][width];
    // Creating Temp Values
    float red_sum = 0, green_sum = 0, blue_sum = 0;
    int counter = 0;

    // Loops through each Column (Height)
    for (int i = 0; i < height; i++)
    {
        // Loops through each Row (Width)
        for (int j = 0; j < width; j++)
        {
            red_sum = 0;
            green_sum = 0;
            blue_sum = 0;
            counter = 0;

            // Creating the 3x3 Box
            for (int x = i - 1; x <= i + 1; x++)
            {
                if (x < 0)
                {
                    x = 0;
                }
                if (x == height)
                {
                    break;
                }
                for (int y = j - 1; y <= j + 1; y++)
                {
                    if (y < 0)
                    {
                        y = 0;
                    }
                    if (y == width)
                    {
                        break;
                    }

                    red_sum += image[x][y].rgbtRed;
                    green_sum += image[x][y].rgbtGreen;
                    blue_sum += image[x][y].rgbtBlue;
                    counter++;
                }
            }
            // Calculates the average for that pixel
            temp[i][j].rgbtRed = (int) round(red_sum / counter);
            temp[i][j].rgbtGreen = (int) round(green_sum / counter);
            temp[i][j].rgbtBlue = (int) round(blue_sum / counter);
        }
    }
    // Loops through each Column (Height)
    for (int i = 0; i < height; i++)
    {
        // Loops through each Row (Width)
        for (int j = 0; j < width; j++)
        {
            // Copies all the temp values over to the original values
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

// Stops max value at 255, which is preventing overflow
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Creating a temporary copy of the image for creating the blur value
    RGBTRIPLE temp[height][width];
    // Creating Temp Values
    float red_sumX = 0, red_sumY = 0, green_sumX = 0, green_sumY = 0, blue_sumX = 0, blue_sumY = 0;
    // Modifer (X axis, Y axis)
    int Mx = 0;
    int My = 0;

    // Loops through each Column (Height)
    for (int i = 0; i < height; i++)
    {
        // Loops through each Row (Width)
        for (int j = 0; j < width; j++)
        {
            red_sumX = 0;
            green_sumX = 0;
            blue_sumX = 0;
            red_sumY = 0;
            green_sumY = 0;
            blue_sumY = 0;

            // Creating the 3x3 Box
            for (int x = i - 1; x < i + 2; x++)
            {
                if (x < 0)
                {
                    x = 0;
                }
                if (x == height)
                {
                    break;
                }
                for (int y = j - 1; y < j + 2; y++)
                {
                    if (y < 0)
                    {
                        y = 0;
                    }
                    if (y == width)
                    {
                        break;
                    }

                    Mx = 0;
                    My = 0;
                    // Modifier check
                    if (x == i - 1)
                    {
                        Mx -= 1;
                    }
                    if (x == i + 1)
                    {
                        Mx += 1;
                    }
                    if (y == j)
                    {
                        Mx = Mx + Mx;
                    }
                    if (y == j - 1)
                    {
                        My -= 1;
                    }
                    if (y == j + 1)
                    {
                        My += 1;
                    }
                    if (x == i)
                    {
                        My = My + My;
                    }

                    red_sumX += image[x][y].rgbtRed * Mx;
                    green_sumX += image[x][y].rgbtGreen * Mx;
                    blue_sumX += image[x][y].rgbtBlue * Mx;

                    red_sumY += image[x][y].rgbtRed * My;
                    green_sumY += image[x][y].rgbtGreen * My;
                    blue_sumY += image[x][y].rgbtBlue * My;
                }
            }
            // Calculates border detection modifier for that pixel
            temp[i][j].rgbtRed = (int) limit(round(sqrt((pow(red_sumX, 2) + pow(red_sumY, 2)))));
            temp[i][j].rgbtGreen = (int) limit(round(sqrt((pow(green_sumX, 2) + pow(green_sumY, 2)))));
            temp[i][j].rgbtBlue = (int) limit(round(sqrt((pow(blue_sumX, 2) + pow(blue_sumY, 2)))));
        }
    }
    // Loops through each Column (Height)
    for (int i = 0; i < height; i++)
    {
        // Loops through each Row (Width)
        for (int j = 0; j < width; j++)
        {
            // Copies all the temp values over to the original values
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}