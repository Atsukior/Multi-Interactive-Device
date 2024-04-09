/*
 * @Date: 2023-12-18 09:41:16
 * @LastEditTime: 2023-12-20 11:36:00
 * @FilePath: \share\total\game.c
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "ts.h"
#include "lcd.h"
#include "bmp.h"
#include "play.h"
#include "color.h"

extern flag_game;
extern flag;

void *click_game(void *arg)
{
    ts_point *p = (ts_point *)malloc(sizeof(ts_point));
    while (1)
    {
        get_ts_point(p); // 获取触摸屏点击事件

        // 判断是否点击了开发板左上角100*100的区域，如果是，则设置 flag 为 0 暂停循环
        if (p->x >= 0 && p->x <= 100 && p->y >= 0 && p->y <= 100)
        {

            flag = 0;

            // system("killall -9 madplay");
            flag_game = 1;
            bmp_display("/sarff/start.bmp", 0, 0);
            break;
        }

        usleep(1000);
    }
    flag = 0;
    flag_game = 0;
    // free(p);
    return NULL;
}

void play_2048_game(int num[][4])
{
    // 设置随机数种子
    srand(time(NULL));

    // 随机在任意空白位置添加2/4,2出现的概率为9/10,4出现的概率为1/10
    // 随机生成两个数字
    add_num(num);
    add_num(num);

    // 显示游戏界面
    show_interface(num);

    // 当flag == 0 时,为无效滑动，不需要再添加数字
    // 当flag == 1 时，为有效滑动，此时需要添加一个数字
    int flag_dir = 0;

    while (check_over(num)) // 游戏是否失败
    {
        if(flag_game == 0)
        {
            move_dir_t dir = get_ts_direction();
            if (dir == MOVE_UP)
            {
                flag_dir = up(num);
            }
            else if (dir == MOVE_DOWN)
            {
                flag_dir = down(num);
            }
            else if (dir == MOVE_LEFT)
            {
                flag_dir = left(num);
            }
            else if (dir == MOVE_RIGHT)
            {
                flag_dir = right(num);
            }

            if (flag_dir == 1)
            {
                add_num(num);
            }

            show_interface(num);

            if (Game_success(num))
            {
                // 设置背景色为纯黑色
                set_background_color();
                printf("game success\n");
                bmp_display("/sarff/dragon.bmp", 100, 0); // 纯属是游戏成功的标志，具体显示什么你自己决定
                break;
            }

            else if (!check_over(num)) // 如果游戏失败了，直接跳出循环，不执行后面的代码
            {
                // 设置背景色为纯黑色
                set_background_color();
                printf("GAME OVER!,zako~❤️\n");
                bmp_display("/sarff/zako.bmp", 176, 0); // 游戏失败的标志
                break;
            }
        }
        else if (flag_game == 1)
        {
            flag = 0;
            break;
        }
    }
}

