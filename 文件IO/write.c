#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define     FILE_PATH_NAME          "abc.c"

int main(int argc, char const *argv[])
{
    int fd = 0;     
    fd = open(FILE_PATH_NAME, O_RDWR | O_CREAT);
    if (fd < 0)
    {
        perror("open file fail");
        return -1;
    }
    else
    {
        printf("%s file open succeed!\n", FILE_PATH_NAME);
    }
    
    ssize_t ret = write(fd, "hello lizh", sizeof("hello lizh"));
    if (ret < 0)
    {
        perror("write msg failed");
        close(fd);
        return -1;
    }
    else
    {
        printf("write %ld bytes\r\n", ret);
    }
    
    

    close(fd);

    return 0;
}
