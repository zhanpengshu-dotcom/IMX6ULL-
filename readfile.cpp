#include "readfile.h"

extern "C"{
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
}

readfile::readfile(QObject *parent) : QObject(parent)
{

} 

/* int readfile::read_file_data_u8(char *FileName,unsigned char *data)
{
    int fd = 0;
    int ret = 0;
    fd = open(FileName,O_RDONLY);
    if(fd < 0){
        printf("open %s false\n",FileName);
        return -1;
    }
    ret = read(fd,data,sizeof(data));
    if(ret < 0){
        printf("read %s false\n",FileName);
        close(fd);
        return -1;
    }
    close(fd);
}
int readfile::read_file_data_u16(char *FileName,unsigned short *data)
{
    int fd = 0;
    int ret = 0;
    fd = open(FileName,O_RDONLY);
    if(fd < 0){
        printf("open %s false\n",FileName);
        return -1;
    }
    ret = read(fd,data,sizeof(data));
    if(ret < 0){
        printf("read %s false\n",FileName);
        close(fd);
        return -1;
    }
    close(fd);
}
int readfile::read_file_data_s16(char *FileName,short *data)
{
    int fd = 0;
    int ret = 0;
    fd = open(FileName,O_RDONLY);
    if(fd < 0){
        printf("open %s false\n",FileName);
        return -1;
    }
    ret = read(fd,data,sizeof(data));
    if(ret < 0){
        printf("read %s false\n",FileName);
        close(fd);
        return -1;
    }
    close(fd);
}
int readfile::read_file_data_int32(char *FileName,int *data)
{
    int fd = 0;
    int ret = 0;
    fd = open(FileName,O_RDONLY);
    if(fd < 0){
        printf("open %s false\n",FileName);
        return -1;
    }
    ret = read(fd,data,sizeof(data));
    if(ret < 0){
        printf("read %s false\n",FileName);
        close(fd);
        return -1;
    }
    close(fd);
} */

static int read_file_data(const char *FileName, void *data, size_t size)
{
    int fd;
    ssize_t ret;

    fd = open(FileName, O_RDONLY);
    if (fd < 0) {
        printf("open %s false\n", FileName);
        return -1;
    }

    ret = read(fd, data, size);
    if (ret < 0) {
        printf("read %s false\n", FileName);
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}

int readfile::read_file_data_u8(const char *FileName, unsigned char *data)
{
    return read_file_data(FileName, data, sizeof(*data));
}

int readfile::read_file_data_u16(const char *FileName, unsigned short *data)
{
    return read_file_data(FileName, data, sizeof(*data));
}

int readfile::read_file_data_s16(const char *FileName, short *data)
{
    return read_file_data(FileName, data, sizeof(*data));
}

int readfile::read_file_data_int32(const char *FileName, int *data)
{
    return read_file_data(FileName, data, sizeof(*data));
}

int readfile::read_file_data_int32_pair(const char *FileName, int *data)
{
    return read_file_data(FileName, data, sizeof(int) * 2);
}

