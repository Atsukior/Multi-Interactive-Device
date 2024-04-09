/*
 * @Date: 2023-12-18 20:27:55
 * @LastEditTime: 2023-12-25 14:13:46
 * @FilePath: \share\2048\score.c
 */
#include "lcd.h"

unsigned char int_num[][138]={{
/*--  文字:  0  --*/
/*--  微软雅黑26;  此字体下对应的点阵为：宽x高=20x46   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x46  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x03,0xFC,0x00,0x07,0xFE,0x00,0x0F,0xFF,0x00,0x1F,0x9F,0x80,0x3E,0x07,0xC0,
0x3E,0x07,0xC0,0x3E,0x07,0xC0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,
0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,
0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x3C,0x03,0xC0,0x3E,0x07,0xC0,
0x3E,0x07,0xC0,0x1F,0x0F,0x80,0x1F,0xFF,0x80,0x0F,0xFF,0x00,0x07,0xFE,0x00,0x00,
0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

},//字符0
{
/*--  文字:  1  --*/
/*--  微软雅黑26;  此字体下对应的点阵为：宽x高=20x46   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x46  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x3C,0x00,0x00,0xFC,0x00,0x03,0xFC,0x00,0x0F,0xFC,0x00,0x1F,0xFC,0x00,
0x1F,0xFC,0x00,0x1E,0x7C,0x00,0x18,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,
0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,
0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,
0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
},//字符1
{
/*--  文字:  2  --*/
/*--  微软雅黑26;  此字体下对应的点阵为：宽x高=20x46   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x46  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x03,0xFC,0x00,0x0F,0xFF,0x00,0x1F,0xFF,0x80,0x3F,0x1F,0x80,0x3E,0x07,0xC0, 
0x7C,0x07,0xC0,0x3C,0x07,0xC0,0x18,0x07,0xC0,0x00,0x07,0xC0,0x00,0x07,0xC0,0x00, 
0x07,0xC0,0x00,0x0F,0x80,0x00,0x1F,0x80,0x00,0x3F,0x00,0x00,0x3E,0x00,0x00,0x7C, 
0x00,0x00,0xF8,0x00,0x01,0xF0,0x00,0x03,0xF0,0x00,0x07,0xE0,0x00,0x0F,0xC0,0x00, 
0x1F,0x80,0x00,0x3F,0x00,0x00,0x7F,0xFF,0xE0,0x7F,0xFF,0xE0,0x7F,0xFF,0xE0,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
},//字符2
{
/*--  文字:  3  --*/
/*--  微软雅黑26;  此字体下对应的点阵为：宽x高=20x46   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x46  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x07,0xFC,0x00,0x0F,0xFF,0x00,0x1F,0xFF,0x80,0x3F,0x1F,0x80,0x3E,0x0F,0xC0, 
0x7C,0x07,0xC0,0x38,0x07,0xC0,0x00,0x07,0xC0,0x00,0x07,0xC0,0x00,0x0F,0x80,0x00, 
0x1F,0x80,0x01,0xFF,0x00,0x01,0xFE,0x00,0x01,0xFF,0x80,0x00,0x3F,0xC0,0x00,0x07, 
0xC0,0x00,0x03,0xE0,0x00,0x03,0xE0,0x00,0x03,0xE0,0x18,0x03,0xE0,0x78,0x03,0xE0, 
0x7C,0x07,0xC0,0x3F,0x0F,0xC0,0x3F,0xFF,0x80,0x1F,0xFF,0x00,0x07,0xFE,0x00,0x01, 
0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
},//字符3
{
/*--  文字:  4  --*/
/*--  微软雅黑26;  此字体下对应的点阵为：宽x高=20x46   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x46  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x3E,0x00,0x00,0x3C,0x00,0x00,0x7C,0x00,0x00,0xF8,0x00,0x00,0xF8,0x00, 
0x01,0xF0,0x00,0x01,0xF0,0x00,0x03,0xE0,0x00,0x03,0xE0,0x00,0x07,0xC0,0x00,0x07, 
0xCF,0x80,0x0F,0x8F,0x80,0x0F,0x0F,0x80,0x1F,0x0F,0x80,0x1E,0x0F,0x80,0x3E,0x0F, 
0x80,0x7C,0x0F,0x80,0x7F,0xFF,0xF0,0x7F,0xFF,0xF0,0x7F,0xFF,0xF0,0x7F,0xFF,0xF0, 
0x00,0x0F,0x80,0x00,0x0F,0x80,0x00,0x0F,0x80,0x00,0x0F,0x80,0x00,0x0F,0x80,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
},//字符4
{
/*--  文字:  5  --*/
/*--  微软雅黑26;  此字体下对应的点阵为：宽x高=20x46   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x46  --*/ 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x0F,0xFF,0xC0,0x0F,0xFF,0xC0,0x0F,0xFF,0xC0,0x0F,0x00,0x00,0x1F,0x00,0x00, 
0x1F,0x00,0x00,0x1F,0x00,0x00,0x1F,0x00,0x00,0x1E,0x00,0x00,0x1E,0xF0,0x00,0x1F, 
0xFE,0x00,0x1F,0xFF,0x00,0x3F,0xFF,0x80,0x3F,0x0F,0xC0,0x3C,0x07,0xC0,0x00,0x07, 
0xC0,0x00,0x03,0xE0,0x00,0x03,0xE0,0x00,0x03,0xE0,0x00,0x03,0xE0,0x1C,0x07,0xC0, 
0x3C,0x07,0xC0,0x3F,0x0F,0xC0,0x1F,0xFF,0x80,0x0F,0xFF,0x00,0x07,0xFE,0x00,0x01, 
0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
},//字符5
{
/*--  文字:  6  --*/
/*--  微软雅黑26;  此字体下对应的点阵为：宽x高=20x46   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x46  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x3E,0x00,0x00,0x3E,0x00,0x00,0x7C,0x00,0x00,0xF8,0x00,0x00,0xF8,0x00, 
0x01,0xF0,0x00,0x03,0xE0,0x00,0x03,0xE0,0x00,0x07,0xC0,0x00,0x07,0xC0,0x00,0x0F, 
0xFE,0x00,0x1F,0xFF,0x00,0x1F,0xFF,0x80,0x3F,0x8F,0xC0,0x3E,0x07,0xC0,0x3E,0x03, 
0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0, 
0x3E,0x03,0xE0,0x3F,0x0F,0xC0,0x1F,0xFF,0x80,0x0F,0xFF,0x80,0x07,0xFE,0x00,0x00, 
0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
},//字符6
{
/*--  文字:  7  --*/
/*--  微软雅黑26;  此字体下对应的点阵为：宽x高=20x46   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x46  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x7F,0xFF,0xE0,0x7F,0xFF,0xE0,0x7F,0xFF,0xE0,0x00,0x07,0xC0,0x00,0x07,0xC0, 
0x00,0x07,0x80,0x00,0x0F,0x80,0x00,0x0F,0x80,0x00,0x1F,0x00,0x00,0x1F,0x00,0x00, 
0x1E,0x00,0x00,0x3E,0x00,0x00,0x3E,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0xF8, 
0x00,0x00,0xF8,0x00,0x00,0xF8,0x00,0x01,0xF0,0x00,0x01,0xF0,0x00,0x03,0xE0,0x00, 
0x03,0xE0,0x00,0x03,0xC0,0x00,0x07,0xC0,0x00,0x07,0xC0,0x00,0x0F,0x80,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
},//字符7
{
/*--  文字:  8  --*/
/*--  微软雅黑26;  此字体下对应的点阵为：宽x高=20x46   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x46  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x03,0xFC,0x00,0x0F,0xFF,0x00,0x1F,0xFF,0x80,0x1F,0x0F,0x80,0x3E,0x07,0xC0, 
0x3E,0x07,0xC0,0x3E,0x07,0xC0,0x3E,0x07,0xC0,0x3E,0x07,0xC0,0x1F,0x0F,0x80,0x1F, 
0xFF,0x80,0x0F,0xFF,0x00,0x0F,0xFF,0x00,0x1F,0xFF,0x80,0x3F,0x0F,0xC0,0x3E,0x07, 
0xC0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0, 
0x7C,0x03,0xE0,0x3F,0x0F,0xC0,0x1F,0xFF,0x80,0x1F,0xFF,0x80,0x07,0xFE,0x00,0x01, 
0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
},//字符8
{
/*--  文字:  9  --*/
/*--  微软雅黑26;  此字体下对应的点阵为：宽x高=20x46   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=24x46  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x07,0xFC,0x00,0x0F,0xFF,0x00,0x1F,0xFF,0x80,0x3F,0x1F,0xC0,0x3E,0x07,0xC0, 
0x7C,0x03,0xC0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C,0x03,0xE0,0x7C, 
0x03,0xE0,0x7E,0x07,0xC0,0x3F,0x0F,0xC0,0x1F,0xFF,0x80,0x1F,0xFF,0x80,0x07,0xFF, 
0x00,0x00,0xFF,0x00,0x00,0x3E,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0xF8,0x00, 
0x01,0xF0,0x00,0x01,0xF0,0x00,0x03,0xE0,0x00,0x03,0xE0,0x00,0x07,0xC0,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
}//字符9
};

void zh_display(const char zh[], int x0, int y0, int w, int h)
{
    int dian; // 第dian个像素点

    for (dian = 0; dian < w * h; dian++)
    {
        // 要在屏幕上的合适位置显示这个像素点

        int x, y; // （x,y)这个dian像素点，在屏幕上的显示位置

        y = y0 + dian / w; // 该点在原始汉字的第dian / w行

        x = x0 + dian % w; // 该点在原始汉字的第dian % w列

        // dian这个像素点取模后在数组zh[]的第几个元素中呢？
        int index = dian / 8; // 表示数组元素的下标

        // zhindex] 包括8个bit位，那么该点到底在第几bit位呢？
        int bit = 7 - dian % 8; // 在字节中的第几bits

        int color; // 这个像素点要显示的颜色

        // 如果该bits为1表示显示颜色，为0表示不显示颜色
        if (zh[index] & (1 << bit))
        {
            // 该像素点在笔划上
            color = 0;
        }
        else
        {
            // 该像素点不在笔划上
            color = 0xff0000;
        }

        lcd_draw_point(x, y, color);
    }
}

void display_integer(int number, int x0, int y0)
{
    int digits[20];
    int count = 0; // 记录数字个数
    do
    {
        digits[count++] = number % 10;
        number /= 10;
    } while (number != 0);
    int j = 0;
    for (j = count - 1; j >= 0; j--)
    {
        zh_display(int_num[digits[j] % 10], x0 += 17, y0, 24, 46);
    }
}
