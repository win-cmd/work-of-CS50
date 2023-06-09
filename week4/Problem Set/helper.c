//four methods that process images
//grayscale,sepia,Reflect,Blur(灰度化、棕褐色化、镜像、模糊)
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int ave = 0;
            float average = (pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0; //整数类型
            if ((average - (int)average) < 0.5)
            {
                ave = (int)average;
            }
            else
            {
                ave = (int)average + 1;
            }
            pixel.rgbtBlue = ave;
            pixel.rgbtGreen = ave;
            pixel.rgbtRed = ave;
            image[i][j] = pixel;
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
            RGBTRIPLE pixel = image[i][j];
            float sepiaRed = .393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue;
            float sepiaGreen = .349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue;
            float sepiaBlue = .272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue;
            int Red = 0;
            int Green = 0;
            int Blue = 0;
            //四舍五入
            if ((sepiaRed - (int)sepiaRed) < 0.5)
            {
                Red = (int)sepiaRed;
            }
            else
            {
                Red = (int)sepiaRed + 1;
            }
            if ((sepiaGreen - (int)sepiaGreen) < 0.5)
            {
                Green = (int)sepiaGreen;
            }
            else
            {
                Green = (int)sepiaGreen + 1;
            }
            if ((sepiaBlue - (int)sepiaBlue) < 0.5)
            {
                Blue = (int)sepiaBlue;
            }
            else
            {
                Blue = (int)sepiaBlue + 1;
            }
            //溢出处理
            if (Red > 255)
            {
                pixel.rgbtRed = 255;
            }
            else
            {
                pixel.rgbtRed = Red;
            }
            if (Green > 255)
            {
                pixel.rgbtGreen = 255;
            }
            else
            {
                pixel.rgbtGreen = Green;
            }
            if (Blue > 255)
            {
                pixel.rgbtBlue = 255;
            }
            else
            {
                pixel.rgbtBlue = Blue;
            }
            image[i][j] = pixel;
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
            RGBTRIPLE pixel = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = pixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //初始化
            float Red = 0.0;
            float Green = 0.0;
            float Blue = 0.0;
            float n = 1.0;
            //先加中间
            Red += image[i][j].rgbtRed;
            Green += image[i][j].rgbtGreen;
            Blue += image[i][j].rgbtBlue;
            //判断是否需要加四周的像素
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                Red += image[i - 1][j - 1].rgbtRed;
                Green += image[i - 1][j - 1].rgbtGreen;
                Blue += image[i - 1][j - 1].rgbtBlue;
                n++;
            }
            if (i - 1 >= 0)
            {
                Red += image[i - 1][j].rgbtRed;
                Green += image[i - 1][j].rgbtGreen;
                Blue += image[i - 1][j].rgbtBlue;
                n++;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                Red += image[i - 1][j + 1].rgbtRed;
                Green += image[i - 1][j + 1].rgbtGreen;
                Blue += image[i - 1][j + 1].rgbtBlue;
                n++;
            }
            if (j - 1 >= 0)
            {
                Red += image[i][j - 1].rgbtRed;
                Green += image[i][j - 1].rgbtGreen;
                Blue += image[i][j - 1].rgbtBlue;
                n++;
            }
            if (j + 1 < width)
            {
                Red += image[i][j + 1].rgbtRed;
                Green += image[i][j + 1].rgbtGreen;
                Blue += image[i][j + 1].rgbtBlue;
                n++;
            }
            if (i + 1 < height && j - 1 >= 0)
            {
                Red += image[i + 1][j - 1].rgbtRed;
                Green += image[i + 1][j - 1].rgbtGreen;
                Blue += image[i + 1][j - 1].rgbtBlue;
                n++;
            }
            if (i + 1 < height)
            {
                Red += image[i + 1][j].rgbtRed;
                Green += image[i + 1][j].rgbtGreen;
                Blue += image[i + 1][j].rgbtBlue;
                n++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                Red += image[i + 1][j + 1].rgbtRed;
                Green += image[i + 1][j + 1].rgbtGreen;
                Blue += image[i + 1][j + 1].rgbtBlue;
                n++;
            }
            Red /= n;
            Green /= n;
            Blue /= n;
            if ((Red - (int)Red) < 0.5)
            {
                temp[i][j].rgbtRed = (int)Red;
            }
            else
            {
                temp[i][j].rgbtRed = (int)Red + 1;
            }
            if ((Green - (int)Green) < 0.5)
            {
                temp[i][j].rgbtGreen = (int)Green;
            }
            else
            {
                temp[i][j].rgbtGreen = (int)Green + 1;
            }
            if ((Blue - (int)Blue) < 0.5)
            {
                temp[i][j].rgbtBlue = (int)Blue;
            }
            else
            {
                temp[i][j].rgbtBlue = (int)Blue + 1;
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}
