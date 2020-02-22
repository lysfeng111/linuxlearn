#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd[2];
	int r;
	char buf[20];
	r = pipe(fd);
	write(fd[1],"hello",5);
	write(fd[1],"world",5);

	r = read(fd[0],buf,20);
	buf[r] = 0;
	printf("%s\n",buf);
	r = read(fd[0],buf,20);
	write(fd[1],"louis",5);
	buf[r]= 0;
	printf("%s\n",buf);
	printf("%d\n",getpid());

	while(1);
}
