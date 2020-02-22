#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
int idx=0;
int fddata;
void handle(int s)
{
	int status;
	if(s == SIGCHLD)
	{
		wait(&status);
		idx ++;
		if(idx == 2)
		{
			close(fddata);
			printf("任务完成");
			exit(-1);
		}
	}
}

int isprimer(int ta)
{
	int i = 2;
	for(;i<ta;i++)
	{
		if(ta%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
main()
{
	int a,b;
	int id = 1;
	int fd[2];
	signal(SIGCHLD,handle);
	pipe(fd);
	while(1)
	{
		if(id == 1)
		{
			a = 2;
			b = 5000;
		}
		if(id == 2)
		{
			a = 5001;
			b = 10000;
		}
		if(fork())
		{
			//父进程
			id ++;
			if(id >2)
			{
				break;
			}
			continue;
		}
		else
		{
			//子进程
			int i;
			close(fd[0]);
			for(i=a;i<=b;i++)
			{
				if(isprimer(i))
				{
					write(fd[1],&i,sizeof(int));
				}
				sched_yield();
			}
			printf("%d任务完成!\n",getpid());
			exit(0);
		}
	}
	int re;
	int r;
	char buf[20];
	//打开文件，准备存储
	close(fd[1]);
	fddata = open("result.txt",O_RDWR|O_CREAT,0666);
	while(1)
	{	
		r = read(fd[0],&re,sizeof(int));
		sprintf(buf,"%d\n",re);
		write(fddata,buf,strlen(buf));
		//sched_yield();
	}
}
