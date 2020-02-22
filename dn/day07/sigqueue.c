#include <stdio.h>
#include <signal.h>
#include <unistd.h>
main()
{
	union sigval val;
	val.sival_int = 9999;

	sigqueue(3650,SIGUSR1,val);
}
