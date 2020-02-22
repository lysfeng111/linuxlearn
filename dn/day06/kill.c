#include <stdio.h>
#include <signal.h>
main()
{
	while(1)
	{
	kill(29395,SIGINT);
	sleep(2);
	}
}
