#include <stdio.h>
#include <fcntl.h>//文件
#include <sys/mman.h>//内存映射

main()
{
	int *p;
	int fd;
	int i;
	fd = open("tmp",O_RDWR|O_CREAT,0666);
	ftruncate(fd,4);//文件大小4个字节
	p=mmap(0,4,PROT_READ|PROT_WRITE,
		MAP_SHARED,fd,0);
	i=0;
	while(1)
	{
		sleep(1);
		*p = i; 
		i++;
	}
	close(fd);
}
