#include <string.h>
#include <math.h>

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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loops through each Column (Height)
    for (int i = 0; i < height; i++)
    {
        // Loops through each Row (Width)
        for (int j = 0; j < width; j++)
        {
            // Creates the sepia filter for the colour Red
            int sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            // Creates the sepia filter for the colour Green
            int sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            // Creates the sepia filter for the colour Blue
            int sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            // Updates each colour with the sepia value
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
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
