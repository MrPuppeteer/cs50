#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;
            int roundAvg = round((blue + green + red) / 3.0);

            image[i][j].rgbtBlue = roundAvg;
            image[i][j].rgbtGreen = roundAvg;
            image[i][j].rgbtRed = roundAvg;
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
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed, sumGreen, sumBlue;
            float counter = 0;
            sumRed = sumGreen = sumBlue = 0;

            for (int h = -1; h <= 1; h++)
            {
                for (int w = -1; w <= 1; w++)
                {
                    if (i + h < 0 || i + h > height - 1)
                    {
                        continue;
                    }
                    if (j + w < 0 || j + w > width - 1)
                    {
                        continue;
                    }

                    sumRed += copy[i + h][j + w].rgbtRed;
                    sumGreen += copy[i + h][j + w].rgbtGreen;
                    sumBlue += copy[i + h][j + w].rgbtBlue;
                    counter++;
                }
            }

            image[i][j].rgbtRed = round(sumRed / counter);
            image[i][j].rgbtGreen = round(sumGreen / counter);
            image[i][j].rgbtBlue = round(sumBlue / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gxRed, gxGreen, gxBlue;
            float gyRed, gyGreen, gyBlue;
            gxRed = gxGreen = gxBlue = 0;
            gyRed = gyGreen = gyBlue = 0;
            int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
            int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

            for (int h = -1; h <= 1; h++)
            {
                for (int w = -1; w <= 1; w++)
                {
                    if (i + h < 0 || i + h > height - 1)
                    {
                        continue;
                    }
                    if (j + w < 0 || j + w > width - 1)
                    {
                        continue;
                    }

                    gxRed += (copy[i + h][j + w].rgbtRed * gx[h + 1][w + 1]);
                    gxGreen += (copy[i + h][j + w].rgbtGreen * gx[h + 1][w + 1]);
                    gxBlue += (copy[i + h][j + w].rgbtBlue * gx[h + 1][w + 1]);

                    gyRed += (copy[i + h][j + w].rgbtRed * gy[h + 1][w + 1]);
                    gyGreen += (copy[i + h][j + w].rgbtGreen * gy[h + 1][w + 1]);
                    gyBlue += (copy[i + h][j + w].rgbtBlue * gy[h + 1][w + 1]);
                }
            }

            int sobelRed = round(sqrt(pow(gxRed, 2) + pow(gyRed, 2)));
            int sobelGreen = round(sqrt(pow(gxGreen, 2) + pow(gyGreen, 2)));
            int sobelBlue = round(sqrt(pow(gxBlue, 2) + pow(gyBlue, 2)));

            image[i][j].rgbtRed = (sobelRed > 255) ? 255 : sobelRed;
            image[i][j].rgbtGreen = (sobelGreen > 255) ? 255 : sobelGreen;
            image[i][j].rgbtBlue = (sobelBlue > 255) ? 255 : sobelBlue;
        }
    }
    return;
}
