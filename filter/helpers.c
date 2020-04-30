#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row = 0; row < height; row++)
    {
        for(int column = 0; column < width; column++)
        {
            int average = (image[row][column].rgbtBlue + image[row][column].rgbtGreen + image[row][column].rgbtRed) / 3;
            image[row][column].rgbtBlue = average;
            image[row][column].rgbtGreen = average;
            image[row][column].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int column = 0; column < (width / 2); column++)
    {
        for(int row = 0; row < height; row++)
        {
            RGBTRIPLE leftPixel = image[row][column];
            image[row][column] = image[row][width - 1 - column];
            image[row][width - 1 - column] = leftPixel;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurredImage[height][width]; // temporary array of blurred rgbtriples

    for(int row = 0; row < height; row++)
    {
        for(int column = 0; column < width; column++)
        {
            int redTotal = 0;
            int greenTotal = 0;
            int blueTotal = 0;
            int count = 0;
            for(int r = row - 1; r < row + 2; r++)
            {
                if(r < 0 || r >= height) // row out of bounds
                {
                    continue;
                }
                for(int c = column - 1; c < column + 2; c++)
                {
                    if(c < 0 || c >= width) // column out of bounds
                    {
                        continue;
                    }
                    // we may now assume that the row and column are within bounds
                    redTotal += image[r][c].rgbtRed;
                    greenTotal += image[r][c].rgbtGreen;
                    blueTotal += image[r][c].rgbtBlue;
                    count++;
                }
            }
            blurredImage[row][column].rgbtRed = (int) redTotal / count; // red average value
            blurredImage[row][column].rgbtGreen = (int) greenTotal / count; // green average value
            blurredImage[row][column].rgbtBlue = (int) blueTotal / count; // blue average value
        }
    }

    // copy the blurred RGBTRIPLE structs to the argument image
    for(int row = 0; row < height; row++)
    {
        for(int column = 0; column < width; column++)
        {
            image[row][column] = blurredImage[row][column];
        }
    }

    return;
}

int getXFactor(int row, int column, int r, int c);
int getYFactor(int row, int column, int r, int c);

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE outlinedImage[height][width]; // temporary array of edge-detected rgbtriples

    for(int row = 0; row < height; row++)
    {
        for(int column = 0; column < width; column++)
        {
            int redTotalX = 0;
            int redTotalY = 0;
            int greenTotalX = 0;
            int greenTotalY = 0;
            int blueTotalX = 0;
            int blueTotalY = 0;

            for(int r = row - 1; r < row + 2; r++)
            {
                if(r < 0 || r >= height) // row out of bounds
                {
                    continue;
                }
                for(int c = column - 1; c < column + 2; c++)
                {
                    if(c < 0 || c >= width) // column out of bounds
                    {
                        continue;
                    }

                    // we may now assume that the row and column are within bounds

                    int xFactor = getXFactor(row, column, r, c);
                    int yFactor = getYFactor(row, column, r, c);

                    redTotalX += image[r][c].rgbtRed * xFactor;
                    redTotalY += image[r][c].rgbtRed * yFactor;
                    greenTotalX += image[r][c].rgbtGreen * xFactor;
                    greenTotalY += image[r][c].rgbtGreen * yFactor;
                    blueTotalX += image[r][c].rgbtBlue * xFactor;
                    blueTotalY += image[r][c].rgbtBlue * yFactor;
                }
            }

            int sobelRed = (int) sqrt((redTotalX * redTotalX ) + (redTotalY * redTotalY));
            sobelRed = sobelRed > 255 ? 255: sobelRed;

            int sobelGreen = (int) sqrt((greenTotalX * greenTotalX ) + (greenTotalY * greenTotalY));
            sobelGreen = sobelGreen > 255 ? 255: sobelGreen;

            int sobelBlue = (int) sqrt((blueTotalX * blueTotalX ) + (blueTotalY * blueTotalY));
            sobelBlue = sobelBlue > 255 ? 255: sobelBlue;

            outlinedImage[row][column].rgbtRed = sobelRed;
            outlinedImage[row][column].rgbtGreen = sobelGreen;
            outlinedImage[row][column].rgbtBlue = sobelBlue;
        }
    }

    // copy the blurred RGBTRIPLE structs to the argument image
    for(int row = 0; row < height; row++)
    {
        for(int column = 0; column < width; column++)
        {
            image[row][column] = outlinedImage[row][column];
        }
    }

    return;
}

int getXFactor(int row, int column, int r, int c)
{
    if(c != column) // Gx is not zero
    {
        int row_column_diff = (r - row) + (c - column);
        if(row_column_diff == -1 || row_column_diff == 1) // -1 or 1
        {
            if(c < column)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else // -2 or 2
        {
            if(c < column)
            {
                return -2;
            }
            else
            {
                return 2;
            }
        }
    }
    else
    {
        return 0;
    }
}

int getYFactor(int row, int column, int r, int c)
{
    if(r != row) // Gy is not zero
    {
        int row_column_diff = (r - row) + (c - column);
        if(row_column_diff == -1 || row_column_diff == 1) // -1 or 1
        {
            if(r < row)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else // -2 or 2
        {
            if(r < row)
            {
                return -2;
            }
            else
            {
                return 2;
            }
        }
    }
    else
    {
        return 0;
    }
}