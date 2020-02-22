#include <stdio.h>
#include <unistd.h>

main()
{
	int r = inputInt("输入菱形半径");
	diamond(r);
	printf("%d\n",getpid());
	while(1);
}
