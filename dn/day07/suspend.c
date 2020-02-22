#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle(int s)
{
	printf("信号干扰！\n");
}
main()
{
	sigset_t sigs;
	sigemptyset(&sigs);
	signal(SIGUSR1,handle);

	sigsuspend(&sigs);	

	printf("over!\n");
}
