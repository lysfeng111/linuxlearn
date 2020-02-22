#include <stdio.h>
#include <unistd.h>

main()
{
	int *p=sbrk(4); //分配4字节整数
	*p = 8888;
	printf("%d\n",*p);
}
