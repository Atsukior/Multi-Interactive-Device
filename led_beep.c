/*
 * @Date: 2023-12-12 09:47:25
 * @LastEditTime: 2023-12-22 11:30:22
 * @FilePath: \share\total\led_beep.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include "ts.h"

int flag_led = 0;
int flag_beep = 0;

extern int flag_led_beep;
extern int flag_exit;
extern int flag;

void *click_led_beep()
{
    ts_point *p = (ts_point *)malloc(sizeof(ts_point));
    while (1)
    {
        get_ts_point(p); // 获取触摸屏点击事件

        // 判断是否点击了开发板左上角100*100的区域，如果是，则切换灯的状态
        if (p->x >= 0 && p->x <= 174 && p->y >= 120 && p->y <= 200)
        {
            flag_led = !flag_led;
            flag_led_beep = 1;
        }
        // 判断是否点击了开发板右下角100*100的区域，如果是，则切换蜂鸣器的状态
        else if (p->x >= 0 && p->x <= 174 && p->y >= 233 && p->y <= 320)
        {
            flag_beep = !flag_beep;
            flag_led_beep = 1;
        }
        else if (p->x >= 0 && p->x <= 100 && p->y >= 0 && p->y <= 100)
        {
            flag = 0;
            flag_led = 0;
            flag_beep = 0;
            flag_led_beep = 0;
            flag_exit = 1;
            bmp_display("/sarff/start.bmp", 0, 0);

            free(p);
            break;
        }
    }
    //free(p);
}

void led_beep_sub()
{
    int fd_led, fd_beep;

    fd_led = open("/sys/kernel/gec_ctrl/led_all", O_RDWR);
    if (fd_led == -1)
    {
        printf("open led error!\n");
        return;
    }

    fd_beep = open("/sys/kernel/gec_ctrl/beep", O_RDWR);
    if (fd_beep == -1)
    {
        printf("open beep error!\n");
        return;
    }

    // pthread_t tid1;
    // pthread_create(&tid1, NULL, (void *)click_led_beep, NULL);

    int k;

    while (!flag_exit)
    {
        if (flag_led_beep)
        {
            if (flag_led == 1)
            {
                // 点亮灯
                k = 1;
                write(fd_led, &k, 4); // 写入1
                printf("LED is ON\n");
                flag_led_beep = 0;
            }
            else
            {
                // 熄灭灯
                k = 0;
                write(fd_led, &k, 4); // 写入0
                printf("LED is OFF\n");
                flag_led_beep = 0;
            }

            if (flag_beep == 1)
            {
                // 打开蜂鸣器
                k = 1;
                write(fd_beep, &k, 4); // 写入1
                printf("Beep is ON\n");
                flag_led_beep = 0;
            }
            else
            {
                // 关闭蜂鸣器
                k = 0;
                write(fd_beep, &k, 4); // 写入0
                printf("Beep is OFF\n");
                flag_led_beep = 0;
            }
            // usleep(10000);
        }
    }
    close(fd_led);
    close(fd_beep);

    flag_led_beep = 0; // 在退出循环后重置标志位
}
