#include <stdio.h>
#include <fcntl.h>//文件
#include <sys/mman.h>//内存映射

main()
{
        int *p;
        int fd;
        fd = open("tmp",O_RDWR);
        p=mmap(0,4,PROT_READ|PROT_WRITE,
                MAP_SHARED,fd,0);
        while(1)
        {
                sleep(1);
		printf("%d\n",*p);
        }
        close(fd);
}

