//problem set
//bulbs.c

#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string bulb = get_string("Message: ");
    for (int i = 0, n = strlen(bulb); i < n; i++)
    {
        //十进制转换为二进制
        int ten = bulb[i];
        int two[BITS_IN_BYTE];
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            two[j] = ten % 2;
            ten /= 2;
        }

        //打印灯泡
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(two[j]);
        }

        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
