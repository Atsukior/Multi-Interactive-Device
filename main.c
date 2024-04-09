/*
 * @Date: 2023-12-07 10:23:09
 * @LastEditTime: 2023-12-26 09:31:49
 * @FilePath: \share\total\main.c
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include "ts.h"
#include "bmp.h"
#include "lcd.h"
#include "flag.h"
#include "play.h"
#include "game.h"
#include "music.h"
#include "led_beep.h"

const char *bmp_files[] = {
    "/sarff/image1", 
    "/sarff/mihoyo", 
    "/sarff/genshin", 
    "/sarff/image2", 
    "/sarff/image3", 
    "/sarff/image4", 
    "/sarff/image5"};
int current_image = 0;
int num_images = sizeof(bmp_files) / sizeof(bmp_files[0]);

extern int flag_game = 0;
extern void *click_game(void *arg);
int score = 0;
int top_score = 0;

extern int flag_music = 1;
extern current_song = 0;
extern void *click_music(void *arg);
extern char *songs[] = {
    "/sarff/music/zood.mp3", 
    "/sarff/music/igotsmoke.mp3", 
    "/sarff/music/distance.mp3"};
extern char *images[] = {
    "/sarff/music/zood.bmp",
    "/sarff/music/igotsmoke.bmp",
    "/sarff/music/distance.bmp"};
extern num_songs = sizeof(songs) / sizeof(songs[0]);

int flag_led_beep = 0; 
int flag_exit = 0; // 定义并初始化 flag_exit 变量

// 创建一个函数，调用ts.c中的get_ts_point，来判断是否按下开发板100*100的区域，即click是否为1
int flag = 114514;

void *click()
{
    ts_point *p = (ts_point *)malloc(sizeof(ts_point));
    while (1)
    {
        get_ts_point(p); // 获取触摸屏点击事件

        // 判断是否点击了开发板左上角100*100的区域，如果是，则设置 flag 为 0 暂停循环
        if (p->x >= 0 && p->x <= 100 && p->y >= 0 && p->y <= 100)
        {
            flag = 0;
        }
        // 判断是否点击了开发板手动播放的区域，如果是，则设置 flag 为 1 继续循环
        else if (p->x >= 547 && p->x <= 785 && p->y >= 60 && p->y <= 125)
        {
            flag = 1;
        }
        // 判断是否点击了开发板自动播放的区域，如果是，则设置 flag 为 2 继续循环
        else if (p->x >= 547 && p->x <= 785 && p->y >= 163 && p->y <= 225)
        {
            flag = 2;
        }
        // 判断是否点击了开发板2048游戏的区域，如果是，则设置 flag 为 3 继续循环
        else if (p->x >= 547 && p->x <= 785 && p->y >= 260 && p->y <= 325)
        {
            flag = 3;
        }
        // 判断是否点击了开发板音乐播放的区域，如果是，则设置 flag 为 4 继续循环
        else if (p->x >= 547 && p->x <= 785 && p->y >= 360 && p->y <= 420)
        {
            flag = 4;
        }
        // 判断是否点击了开发板led&蜂鸣器的区域，如果是，则设置 flag 为 5 继续循环
        else if (p->x >= 20 && p->x <= 145 && p->y >= 320 && p->y <= 425)
        {
            flag = 5;
        }
    }
}

int main()
{
    lcd_open();

    int num_images = 7;
    // int i;

    pthread_t tid1;
    pthread_create(&tid1, NULL, (void *)click, NULL);

    if (Lcd_Init() == -1)
    {
        printf("LCD initialize error!\n");
        return -1;
    }

    bmp_display("/sarff/start.bmp", -30, 0);

    // Lcd_Uninit();
    while (1)
    {
        if (flag == 0)
        {
            // 返回主界面
            flag = 114514;                         // 重置flag为114514
            current_image = 0;                     // 重置当前图片索引为0
            bmp_display("/sarff/start.bmp", 0, 0); // 显示起始界面

            flag = 114514; // 重置 flag 的值为默认值

            // 添加延时，以避免消耗过多的 CPU 资源
            usleep(100000);
        }
        else if (flag == 1)
        {

            ts_point point;
            get_ts_point(&point); // 获取触摸屏点击事件

            move_dir_t direction = get_ts_direction(); // 获取手指在触摸屏上的滑动方向

            if (direction == MOVE_UP)
            {
                current_image++; // 切换到下一张图片
                if (current_image >= num_images)
                {
                    current_image = 0; // 如果已经是最后一张图片，则切换到第一张图片
                }
            }
            else if (direction == MOVE_DOWN)
            {
                current_image--; // 切换到上一张图片
                if (current_image < 0)
                {
                    current_image = num_images - 1; // 如果已经是第一张图片，则切换到最后一张图片
                }
            }
            else if (direction == MOVE_LEFT)
            {
                current_image++; // 切换到下一张图片
                if (current_image >= num_images)
                {
                    current_image = 0; // 如果已经是最后一张图片，则切换到第一张图片
                }
            }
            else if (direction == MOVE_RIGHT)
            {
                current_image--; // 切换到上一张图片
                if (current_image < 0)
                {
                    current_image = num_images - 1; // 如果已经是第一张图片，则切换到最后一张图片
                }
            }

            // 根据当前图片索引显示图片
            bmp_display(bmp_files[current_image], 0, 0);

        }
        else if (flag == 2)
        {

            bmp_display(bmp_files[current_image], 0, 0);
            usleep(1000000); // 延时1秒钟
            current_image++;
            if (current_image == 7)
            {
                current_image = 0;
            }

        }
        else if (flag == 3)
        {
            int num[4][4] = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}};

            // 设置背景为原神
            bmp_display("/sarff/image4", 0, 0);

            pthread_t thread_game;
            pthread_create(&thread_game, NULL,click_game, NULL);

            // 开始游戏
            play_2048_game(num);

            if (score >= top_score)
            {
                top_score = score;
            }

            score = 0;

            pthread_join(thread_game, NULL);

            flag = 0;
        }
        else if (flag == 4)
        {
            // 设置背景为丁真
            bmp_display("/sarff/music/zood.bmp", 0, 0);

            // 创建线程来处理点击事件和音乐播放
            pthread_t thread_music;
            pthread_create(&thread_music, NULL, click_music, NULL);

            char command[100]; // 添加 command 变量的定义

            // 播放第一首音乐
            sprintf(command, "madplay %s", songs[current_song]);
            system(command);

            // 等待点击事件线程结束
            pthread_join(thread_music, NULL);

        }
        else if (flag == 5)
        {
            // 设置背景为原神
            bmp_display("/sarff/bocchi.bmp", 0, 0);

            //printf("%d\n", flag);

            // 创建线程来处理点击事件和led&蜂鸣器
            pthread_t thread_led_beep;
            pthread_create(&thread_led_beep, NULL, click_led_beep, NULL);

            // 开始led&蜂鸣器
            led_beep_sub();

            flag_exit = 0; // 程序退出时的清理工作

            // 等待点击事件线程结束
            pthread_join(thread_led_beep, NULL);

        }
        // 添加延时，以避免消耗过多的 CPU 资源
        usleep(100000);
    }

    lcd_close();

    return 0;
}