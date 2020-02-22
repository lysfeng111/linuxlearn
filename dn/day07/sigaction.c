#include <stdio.h>
#include <signal.h>
#include <unistd.h>
/*void handle(int s)
{
	printf("OOOK!\n");
	sleep(5);
	printf("K0000!\n");
}*/
void handle(int s, siginfo_t* info,void *d)
{
	printf("OOOK:%d!\n",info->si_int);
	sleep(5);
	printf("K0000!\n");
}
main()
{
	struct sigaction act={0};
	
	//act.sa_handler=handle;
	act.sa_sigaction=handle;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGINT);
	act.sa_flags=SA_SIGINFO;

	sigaction(SIGUSR1,&act,0);
	while(1);
}
