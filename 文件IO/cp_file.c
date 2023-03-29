#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
 *  执行格式:  ./cp_file abc.c a.c
*/

int main(int argc, char const *argv[])
{
    int     src_fd          = -1;
    int     target_fd       = -1;     
    ssize_t ret             = -1;
    char    read_buf[128]   = {0};

    /* 判断参数是否是3个 */
    if (argc != 3)
    {
        printf("执行格式错误!\r\n 应当为:./cp_file xxx.c xxx.c\r\n");
        return -1;
    }
    
    // printf("src = %s, target = %s\r\n", argv[1], argv[2]);

    /* 打开源文件 */
    src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0)
    {
        perror("Open src file failed");
        return -1;
    }

    /* 打开目标文件 */
    target_fd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC);
    if (target_fd < 0)
    {
        perror("Open target file failed");
        close(src_fd);
        return -1;
    }    

    /* 循环读写，犹如抄作业，先读后写 */
    while(1)
    {
        /* 清空缓存 */
        bzero(read_buf, sizeof(read_buf));

        /* 先读取src文件的内容 */
        ret = read(src_fd, read_buf, sizeof(read_buf));

        /* 判断是否读取成功,再把内容写入到target文件 */
        if (ret > 0)
        {
            write(target_fd, read_buf, ret);
            printf("读取%ld个字节\r\n", ret);
        }
        else
        {
            printf("读取结束！\r\n");
            break;
        }
    }

    /* 关闭文件 */
    close(src_fd);
    close(target_fd);

    return 0;
    
}
