#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>	//管道
#include <sys/socket.h>
#include <signal.h>
#include <stdlib.h>
int fd;
int i;
void end(int s)
{
	//关闭管道
	close(fd);
	exit(-1);
}
main()
{
	//打开管道
	signal(SIGINT,end);
	fd=open("my.pipe",O_RDWR);
	shutdown(fd,SHUT_WR);//关闭写
	while(1)
	{
		read(fd,&i,4);
		printf("%d\n",i);
	}
}
