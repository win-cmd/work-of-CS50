//This is a program to recover the image of the camera.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");//argv[1]为文件名，类型为字符串，自动读取到\0结束
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    BYTE *buffer = malloc(sizeof(BYTE) * BLOCK_SIZE);
    int index = 0;//文件序号
    char newfile[8];//文件名
    FILE *outptr = NULL;//文件写入指针

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        //判断是否为照片头
        if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && buffer[3] > 223
            && buffer[3] < 240)//0xff=255,0xd8=216,0xff=255,0xe?=1110????
        {
            //保存文件
            if (index != 0)//第一个照片创建前无需保存
            {
                fclose(outptr);
            }
            //创建新文件
            sprintf(newfile, "%03d.jpg", index);
            outptr = fopen(newfile, "w");
            if (outptr == NULL)
            {
                printf("Could not create %s.\n", newfile);
                return 1;
            }
            index++;
        }
        //寻找到第一个照片头之前无需写新文件
        if (index != 0)
        {
            //将buffer指向的512B大小的块写入创建的文件中
            fwrite(buffer, 1, BLOCK_SIZE, outptr);
        }
    }

    // 释放buffer
    free(buffer);
    // close outfile
    fclose(outptr);
    // close file
    fclose(file);

    return 0;
}
