#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
int fd,cfd;

main()
{
	int r;
	struct sockaddr_in addr;
	char buf[1024];
	char strres[1024];
	
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd==-1) printf("1:%m\n"),exit(-1);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	addr.sin_addr.s_addr = inet_addr("172.16.34.56");

	r = bind(fd,(struct sockaddr*)&addr,sizeof(addr));
	if(r==-1) printf("4:%m\n"),exit(-1);	

	r = listen(fd,10);
	if(r==-1) printf("3:%m\n"),exit(-1);

	cfd = accept(fd,0,0);
	if(cfd == -1) printf("4:%m\n"),exit(-1);

	sprintf(strres,
		"HTTP/1.1 200 OK\r\n"
		"Server: tarena2.0\r\n"
		"Content-Type: text/html\r\n"
		"Content-Length: 28\r\n"
		"Connection: keep-alive\r\n"
		"\r\n"
		"<font color=red>Hell0</font>");
	while(1)
	{
		r = recv(cfd,buf,1024,0);
		if(r>0)
		{
			buf[r]=0;
			printf("接收数据：%s\n",buf);
			send(cfd,strres,strlen(strres),0);
		}
		else
			break;
	}
	close(cfd);
	close(fd);
}
