/*
 * @Date: 2023-12-20 11:39:59
 * @LastEditTime: 2023-12-21 18:41:14
 * @FilePath: \share\total\music.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "ts.h"
#include "lcd.h"
#include "bmp.h"

extern flag_music;
extern flag;
extern current_song;
const char *songs[];
const char *images[];
extern num_songs;
int is_playing = 1; // 初始状态为正在播放

char command[100];

void *click_music(void *arg)
{
    ts_point *p = (ts_point *)malloc(sizeof(ts_point));
    while (flag_music)
    {
        get_ts_point(p); // 获取触摸屏点击事件

        // 暂停或继续播放：565<x<640, 330<y<390
        if (p->x >= 600 && p->x <= 665 && p->y >= 350 && p->y <= 410)
        {
            if (is_playing)
            {
                system("killall -STOP madplay"); // 暂停当前播放
                is_playing = 0;                  // 更新播放状态为暂停
            }
            else
            {
                system("killall -CONT madplay"); // 继续当前播放
                is_playing = 1;                  // 更新播放状态为正在播放
            }
            // usleep(500000); // 延时0.5秒
        }

        // 上一首播放：505<x<565, 330<y<390
        else if (p->x >= 525 && p->x <= 590 && p->y >= 350 && p->y <= 410)
        {
            system("killall -9 madplay");                              // 停止当前播放
            current_song = (current_song + num_songs - 1) % num_songs; // 切换到上一首
            sprintf(command, "madplay %s &", songs[current_song]);
            system(command); // 播放上一首
            bmp_display(images[current_song], 0, 0);
            // usleep(500000);  // 延时0.5秒

            is_playing = 1; // 将 is_playing 重置为 1，以确保播放状态正确

            continue; // 继续下一次循环，等待下一次触摸操作
        }
        // 下一首播放：640<x<700, 330<y<390
        else if (p->x >= 675 && p->x <= 735 && p->y >= 350 && p->y <= 410)
        {
            system("killall -9 madplay");                  // 停止当前播放
            current_song = (current_song + 1) % num_songs; // 切换到下一首
            sprintf(command, "madplay %s &", songs[current_song]);
            system(command); // 播放下一首
            bmp_display(images[current_song], 0, 0);
            // usleep(500000); // 延时0.5秒

            is_playing = 1;  // 将 is_playing 重置为 1，以确保播放状态正确

            continue; // 继续下一次循环，等待下一次触摸操作
        }

        // 返回主界面：0<x<100, 0<y<100
        else if (p->x >= 0 && p->x <= 100 && p->y >= 0 && p->y <= 100)
        {
            system("killall -9 madplay");          // 停止当前播放
            flag = 0;                              // 重置flag，返回主界面
            flag_music = 0;
            bmp_display("/sarff/start.bmp", 0, 0); // 显示起始界面

            free(p);
            break; // 跳出循环
        }

        // 重新获取下一次触摸屏点击事件
        get_ts_point(p);

        // usleep(1000);
    }
    flag = 0;
    flag_music = 1;
    // free(p);
    return NULL;
}

void play_music()
{
    while (flag_music)
    {
        // 构建播放命令
        sprintf(command, "madplay %s", songs[current_song]);

        // 播放当前的音乐文件
        system(command);

        // 播放下一首音乐
        current_song = (current_song + 1) % num_songs;
    }
}