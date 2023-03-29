#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define     FILE_PATH_NAME          "abc.c"

int main(int argc, char const *argv[])
{
    int fd = -1;     
    ssize_t ret = -1;
    char read_buf[128] = {0};

    fd = open(FILE_PATH_NAME, O_RDWR | O_CREAT | O_TRUNC);
    if (fd < 0)
    {
        perror("open file fail");
        return -1;
    }
    else
    {
        printf("%s file open succeed!\n", FILE_PATH_NAME);
    }
    
    ret = write(fd, "hello lizh\n", sizeof("hello lizh\n"));
    if (ret < 0)
    {
        perror("write msg failed");
        goto ERROR;
    }
    else
    {
        printf("write %ld bytes\r\n", ret);
    }
    
    ret = lseek(fd, 0, SEEK_SET);
    if (ret < 0)
    {
        perror("offset file failed");
        goto ERROR;
    }
    else 
    {
        printf("偏移量为%ld\r\n", ret);
    }

    ret = read(fd, read_buf, sizeof(read_buf));
    if (fd < 0)
    {
        perror("read file failed");
        goto ERROR;
    }
    else
    {
        printf("读取到%ld个字节,内容为%s\r\n", ret, read_buf);
    }
    
    close(fd);
    return 0;

ERROR:
    close(fd);
    return -1;
    
}
