#include <stdio.h>
#include <unistd.h>
extern char **environ;

int main(/*int args,char *argv[],char* arge[]*/)
{
	/*
	while(*arge)
	{
		printf("%s\n",*arge);
		arge++;
	}*/
	/*
	int i=0;
	while(arge[i])
	{
		printf("%s\n",arge[i]);
		i++;
	}*/

	while(*environ)
	{
		printf("%s\n",*environ);
		environ++;
	}
}
