#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
void deal(int s)
{
	int status;
	wait(&status);
	printf("回收中...");
	sleep(5);
	printf("回收完毕：%d\n",WEXITSTATUS(status));
}

main()
{
	if(fork() == 0)
	{
		//child
		printf("child!\n");
		sleep(20);
		printf("退出！\n");
		exit(88);
	}
	else
	{
		//parent;
		signal(17,deal);
		sleep(20000);
		printf("parent!\n");
	}
}
