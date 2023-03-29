#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define     FILE_PATH_NAME          "abc.c"

int main(int argc, char const *argv[])
{
    int fd = 0;     
    fd = open(FILE_PATH_NAME, O_RDONLY | O_CREAT);
    if (fd < 0)
    {
        perror("open file fail");
        return -1;
    }
    else
    {
        printf("%s file open succeed!\n", FILE_PATH_NAME);
    }
    
    close(fd);

    return 0;
}
