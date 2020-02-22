#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

main()
{
	int fd = open("test.txt",O_RDWR);
	if(fork())
	{
		write(fd,"Hello",5);
		close(fd);
	}
	else
	{
		write(fd,"workd",5);
		close(fd);
	}
}
