#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define     LCD_PATH_NAME               "/dev/fb0"

int main(int argc, char const *argv[])
{
    int lcd_fd = -1;
    int color = 0xff1100;
    int i = 0;
    int j = 0;

    /* 打开LCD屏幕 */
    lcd_fd = open(LCD_PATH_NAME, O_RDWR);
    if (lcd_fd < 0)
    {   
        perror("Open lcd dev failed");
        return -1;
    }

    /* 向LCD屏幕写入颜色 */
    for (i = 0; i < 480; i++)
    {
        for (j = 0; j < 800; j++)
        {
            write(lcd_fd,  &color, sizeof(int));
        }
        
    }
    
    

    /* 关闭LCD屏 */
    close(lcd_fd);




    return 0;
}
