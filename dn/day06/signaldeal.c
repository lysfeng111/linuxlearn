#include <unistd.h>
#include <stdio.h>
#include <signal.h>
void handle(int s)
{
	printf("我是信号发生！\n");
}

main()
{
	signal(SIGINT,handle);
	while(1)
	{
		printf("进程在执行！%d\n",getpid());
		sleep(1);
	}
}
