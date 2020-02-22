#include <stdio.h>
#include <stdlib.h>

void fun()
{
	printf("over");
}

main()
{
	atexit(fun);
	printf("Process!\n");
}
