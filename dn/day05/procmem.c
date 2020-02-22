#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

main()
{
	int a=20;
	if(frok())
	{
		printf("parent:%d\n",a);
	}
	else
	{
		printf("parent:%d\n",a);
	}
}
