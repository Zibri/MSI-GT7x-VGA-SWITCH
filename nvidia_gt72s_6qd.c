#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd1=-1;
    unsigned char data=0x49;
    unsigned char data2=0x01;

    fd1=open("/dev/port",O_RDWR|O_NDELAY);
    if ( fd1 < 0 ) return fd1;

    lseek(fd1,(0x70),SEEK_SET);
    write(fd1,&data,1);

    lseek(fd1,(0x71),SEEK_SET);
    write(fd1,&data2,1);


    return 0;
}

