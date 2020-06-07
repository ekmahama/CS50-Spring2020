#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE tempB = image[i][j].rgbtBlue;
            BYTE tempG = image[i][j].rgbtGreen;
            BYTE tempR = image[i][j].rgbtRed;

            // Set Each pixel color is average of the RGB of the pixel
            int pixAvg = round((tempR + tempG + tempB) / 3.0);
            image[i][j].rgbtBlue = pixAvg;
            image[i][j].rgbtGreen = pixAvg;
            image[i][j].rgbtRed = pixAvg;
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
            BYTE tempB = image[i][j].rgbtBlue;
            BYTE tempG = image[i][j].rgbtGreen;
            BYTE tempR = image[i][j].rgbtRed;

            // Calculate each pixel color as follows
            int newR = round(.393 * tempR + .769 * tempG + .189 * tempB);
            int newG = round(.349 * tempR + .686 * tempG + .168 * tempB);
            int newB = round(.272 * tempR + .534 * tempG + .131 * tempB);

            // Cap pixel color at 255
            image[i][j].rgbtBlue = (newB > 255) ? 255 : newB;
            image[i][j].rgbtRed = (newR > 255) ? 255 : newR;
            image[i][j].rgbtGreen = (newG > 255) ? 255 : newG;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];

            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy image into a temporary array
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Top left Corners
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i][j + 1].rgbtBlue +
                                              temp[i + 1][j].rgbtBlue + temp[i + 1][j + 1].rgbtBlue) /
                                             4.0);

                image[i][j].rgbtRed = round((temp[i][j].rgbtRed + temp[i][j + 1].rgbtRed +
                                             temp[i + 1][j].rgbtRed + temp[i + 1][j + 1].rgbtRed) /
                                            4.0);

                image[i][j].rgbtGreen = round((temp[i][j].rgbtGreen + temp[i][j + 1].rgbtGreen +
                                               temp[i + 1][j].rgbtGreen + temp[i + 1][j + 1].rgbtGreen) /
                                              4.0);
            }
            // Lower right corner
            else if ((i == height - 1) && (j == width - 1))
            {
                image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i][j - 1].rgbtBlue +
                                              temp[i - 1][j].rgbtBlue + temp[i - 1][j - 1].rgbtBlue) /
                                             4.0);

                image[i][j].rgbtRed = round((temp[i][j].rgbtRed + temp[i][j - 1].rgbtRed +
                                             temp[i - 1][j].rgbtRed + temp[i - 1][j - 1].rgbtRed) /
                                            4.0);

                image[i][j].rgbtGreen = round((temp[i][j].rgbtGreen + temp[i][j - 1].rgbtGreen +
                                               temp[i - 1][j].rgbtGreen + temp[i - 1][j - 1].rgbtGreen) /
                                              4.0);
            }
            // Upper right corner
            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i][j - 1].rgbtBlue +
                                              temp[i + 1][j].rgbtBlue + temp[i + 1][j - 1].rgbtBlue) /
                                             4.0);

                image[i][j].rgbtRed = round((temp[i][j].rgbtRed + temp[i][j - 1].rgbtRed +
                                             temp[i + 1][j].rgbtRed + temp[i + 1][j - 1].rgbtRed) /
                                            4.0);

                image[i][j].rgbtGreen = round((temp[i][j].rgbtGreen + temp[i][j - 1].rgbtGreen +
                                               temp[i + 1][j].rgbtGreen + temp[i + 1][j - 1].rgbtGreen) /
                                              4.0);
            }
            // Lower Left corner
            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i - 1][j].rgbtBlue +
                                              temp[i][j + 1].rgbtBlue + temp[i - 1][j + 1].rgbtBlue) /
                                             4.0);

                image[i][j].rgbtRed = round((temp[i][j].rgbtRed + temp[i - 1][j].rgbtRed +
                                             temp[i][j + 1].rgbtRed + temp[i - 1][j + 1].rgbtRed) /
                                            4.0);

                image[i][j].rgbtGreen = round((temp[i][j].rgbtGreen + temp[i - 1][j].rgbtGreen +
                                               temp[i][j + 1].rgbtGreen + temp[i - 1][j + 1].rgbtGreen) /
                                              4.0);
            }

            // Toper Edge
            else if (i == 0 && (j > 0 && j < width - 1))
            {
                // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i][j - 1].rgbtBlue +
                                              temp[i + 1][j + 1].rgbtBlue + temp[i + 1][j - 1].rgbtBlue +
                                              temp[i + 1][j].rgbtBlue) /
                                             6.0);
                // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtRed = round((temp[i][j].rgbtRed + temp[i][j + 1].rgbtRed + temp[i][j - 1].rgbtRed +
                                             temp[i + 1][j + 1].rgbtRed + temp[i + 1][j - 1].rgbtRed +
                                             temp[i + 1][j].rgbtRed) /
                                            6.0);
                // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtGreen = round((temp[i][j].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i][j - 1].rgbtGreen +
                                               temp[i + 1][j + 1].rgbtGreen + temp[i + 1][j - 1].rgbtGreen +
                                               temp[i + 1][j].rgbtGreen) /
                                              6.0);
            }

            // Lower Edge
            else if (i == height - 1 && (j > 0 && j < width - 1))
            {
                // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i][j - 1].rgbtBlue +
                                              temp[i - 1][j - 1].rgbtBlue + temp[i - 1][j + 1].rgbtBlue +
                                              temp[i - 1][j].rgbtBlue) /
                                             6.0);
                // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtRed = round((temp[i][j].rgbtRed + temp[i][j + 1].rgbtRed + temp[i][j - 1].rgbtRed +
                                             temp[i - 1][j - 1].rgbtRed + temp[i - 1][j + 1].rgbtRed +
                                             temp[i - 1][j].rgbtRed) /
                                            6.0);
                // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtGreen = round((temp[i][j].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i][j - 1].rgbtGreen +
                                               temp[i - 1][j - 1].rgbtGreen + temp[i - 1][j + 1].rgbtGreen +
                                               temp[i - 1][j].rgbtGreen) /
                                              6.0);
            }
            // Left Edge
            else if ((i > 0 && i < height - 1) && j == 0)
            { // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i + 1][j].rgbtBlue +
                                              temp[i + 1][j + 1].rgbtBlue + temp[i - 1][j + 1].rgbtBlue +
                                              temp[i][j + 1].rgbtBlue) /
                                             6.0);
                // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtRed = round((temp[i][j].rgbtRed + temp[i - 1][j].rgbtRed + temp[i + 1][j].rgbtRed +
                                             temp[i + 1][j + 1].rgbtRed + temp[i - 1][j + 1].rgbtRed +
                                             temp[i][j + 1].rgbtRed) /
                                            6.0);
                // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtGreen = round((temp[i][j].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i + 1][j].rgbtGreen +
                                               temp[i + 1][j + 1].rgbtGreen + temp[i - 1][j + 1].rgbtGreen +
                                               temp[i][j + 1].rgbtGreen) /
                                              6.0);
            }
            // Right Edge
            else if ((i > 0 && i < height - 1) && j == width - 1)
            { // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i + 1][j].rgbtBlue +
                                              temp[i + 1][j - 1].rgbtBlue + temp[i - 1][j - 1].rgbtBlue +
                                              temp[i][j - 1].rgbtBlue) /
                                             6.0);
                // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtRed = round((temp[i][j].rgbtRed + temp[i - 1][j].rgbtRed + temp[i + 1][j].rgbtRed +
                                             temp[i + 1][j - 1].rgbtRed + temp[i - 1][j - 1].rgbtRed +
                                             temp[i][j - 1].rgbtRed) /
                                            6.0);
                // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtGreen = round((temp[i][j].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i + 1][j].rgbtGreen +
                                               temp[i + 1][j - 1].rgbtGreen + temp[i - 1][j - 1].rgbtGreen +
                                               temp[i][j - 1].rgbtGreen) /
                                              6.0);
            }
            else
            { // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i + 1][j].rgbtBlue +
                                              temp[i][j - 1].rgbtBlue + temp[i][j + 1].rgbtBlue +
                                              temp[i - 1][j - 1].rgbtBlue + temp[i + 1][j + 1].rgbtBlue +
                                              temp[i + 1][j - 1].rgbtBlue + temp[i - 1][j + 1].rgbtBlue) /
                                             9.0);
                // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtRed = round((temp[i][j].rgbtRed + temp[i - 1][j].rgbtRed + temp[i + 1][j].rgbtRed +
                                             temp[i][j - 1].rgbtRed + temp[i][j + 1].rgbtRed +
                                             temp[i - 1][j - 1].rgbtRed + temp[i + 1][j + 1].rgbtRed +
                                             temp[i + 1][j - 1].rgbtRed + temp[i - 1][j + 1].rgbtRed) /
                                            9.0);
                // Each pixel color is average of neighbouring pixel color
                image[i][j].rgbtGreen = round((temp[i][j].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i + 1][j].rgbtGreen +
                                               temp[i][j - 1].rgbtGreen + temp[i][j + 1].rgbtGreen +
                                               temp[i - 1][j - 1].rgbtGreen + temp[i + 1][j + 1].rgbtGreen +
                                               temp[i + 1][j - 1].rgbtGreen + temp[i - 1][j + 1].rgbtGreen) /
                                              9.0);
            }
        }
    }

    return;
}