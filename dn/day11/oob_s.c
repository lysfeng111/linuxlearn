#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <fcntl.h>
int fd,cfd;
void handle(int s)
{
	char data[100];
	int r;
	if(s==SIGURG)
	{
	r = recv(cfd,data,99,MSG_OOB);
	
	data[r] = 0;
	printf("带外数据：%s\n",data);
	}
}

main()
{
	int fd,cfd;
	int r;
	int type = 1;
	struct sockaddr_in addr;
	char buf[100];
	
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd==-1) printf("1:%m\n"),exit(-1);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	addr.sin_addr.s_addr = inet_addr("172.16.34.56");

	r = bind(fd,(struct sockaddr*)&addr,sizeof(addr));
	if(r==-1) printf("4:%m\n"),exit(-1);	

	r = listen(fd,10);
	if(r==-1) printf("3:%m\n"),exit(-1);

	signal(SIGURG,handle);
	fcntl(cfd,F_SETOWN,getpid());

	cfd = accept(fd,0,0);
	if(cfd == -1) printf("4:%m\n"),exit(-1);
	while(1)
	{
		r = recv(cfd,buf,99,0);
		if(r>0)
		{
			buf[r]=0;
			printf("接收数据：%s\n",buf);
		}
		else
			break;
	}
	close(cfd);
	close(fd);
}
