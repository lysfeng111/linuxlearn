#include <stdio.h>
#include <signal.h>

main()
{
	int sum=0;
	int i;
	sigset_t sigs,sigp;
	sigemptyset(&sigs);
	sigemptyset(&sigp);
	sigaddset(&sigs,SIGINT);
	sigprocmask(SIG_BLOCK,&sigs,0);
	for(i=1;i<=10;i++)
	{
		sum+=i;
		sigpending(&sigp);
		if(sigismember)
		sleep(1);
	}
	printf("sum=%d\n",sum);

	sigprocmask(SIG_UNBLOCK,&sigs,0);
	printf("Over!\n");
}
