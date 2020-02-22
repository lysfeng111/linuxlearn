#include <stdio.h>
#include <unistd.h>

int main()
{
	int r=execlp("ls","l","-l",NULL);
	printf("结束%d\n",r);
	return 0;
}
