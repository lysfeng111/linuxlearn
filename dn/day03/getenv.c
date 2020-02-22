#include <stdlib.h>
#include <stdio.h>

int main()
{

	char *val;
	val = getenv("PATH");
	printf("%s\n",val);
	return 0;
}
