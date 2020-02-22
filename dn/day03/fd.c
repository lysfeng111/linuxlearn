#include <stdlib.h>
#include <stdio.h>

main()
{
	//printf("%d\n",getpid());
	//while(1);
	/*
	int r = write(0,"Hello\n",6);
	write(1,"world\n",6);
	write(2,"louis\n",6);	
	int a=20;
	write(1,&a,4);
 	*/
	char buf[32];
	//memset(buf,0,32);
	bzero(buf,32);		

	int r=read(0,buf,30);
	printf("实际输入：%d\n",r);
	if(r>0)
	{
	buf[r]='\0';
	printf("::%s\n",buf);
	}
	if(r==0)
	{
		printf("ctrl+d\n");
	}
	if(r==-1)
	{
		printf("输入错误\n");
	}
}
