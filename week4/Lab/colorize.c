//bmp文件读取为image数组，且已变为rgb类型
//改变bmp文件的黑色像素(rgb)为红色像素(rgb)

#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            if (pixel.rgbtBlue == 0 && pixel.rgbtGreen == 0 && pixel.rgbtRed == 0)
            {
                pixel.rgbtBlue = 0;
                pixel.rgbtGreen = 0;
                pixel.rgbtRed = 255;
            }
            image[i][j] = pixel;
        }
    }

}
