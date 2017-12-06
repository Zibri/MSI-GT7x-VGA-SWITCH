#include <getopt.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

char *pname;

void
print_usage ()
{
  printf ("MSI VGA Select V0.2 by Zibri\n");
  printf ("http://www.zibri.org\n\n");
  printf ("Usage: %s%s -s/-i/-n/-t\n",geteuid() != 0 ? "sudo ":"",pname);
  exit (EXIT_FAILURE);
}

unsigned char getvga() 
{
    int fd1=-1;
    unsigned char data=0x4c;      // change to 0x49 if you have MSI GT73VR with bios E17A1IMS.10A
    unsigned char data2=0xff;

    fd1=open("/dev/port",O_RDWR|O_NDELAY);
    if ( fd1 < 0 ) print_usage ();;

    lseek(fd1,(0x70),SEEK_SET);
    write(fd1,&data,1);

    lseek(fd1,(0x71),SEEK_SET);
    read(fd1,&data2,1);


    return data2;

}
void setvga(unsigned char data2) 
{
    int fd1=-1;
    unsigned char data=0x4c;      // change to 0x49 if you have MSI GT73VR with bios E17A1IMS.10A

    fd1=open("/dev/port",O_RDWR|O_NDELAY);
    if ( fd1 < 0 ) print_usage ();;

    lseek(fd1,(0x70),SEEK_SET);
    write(fd1,&data,1);

    lseek(fd1,(0x71),SEEK_SET);
    write(fd1,&data2,1);

}
int main(int argc, char *argv[])
{
  int option = 0;
  pname=argv[0];
  while ((option = getopt (argc, argv, "sint")) != -1)
    {
      switch (option)
	{
	case 's':
          printf("%s\n",getvga() == 0x00 ? "Intel" : "Nvidia");
	  break;
	case 'i':
          setvga(0x00);
          printf("%s\n",getvga() == 0x00 ? "Intel" : "Nvidia");
	  break;
	case 'n':
          setvga(0x01);
          printf("%s\n",getvga() == 0x00 ? "Intel" : "Nvidia");
	  break;
	case 't':
          setvga(getvga() ^ 0x01);
          printf("%s\n",getvga() == 0x00 ? "Intel" : "Nvidia");
	  break;
	default:
	  print_usage (argv[0]);
	}
    }

  if (optind==1) print_usage (argv[0]);
exit (EXIT_SUCCESS);
}

