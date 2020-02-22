#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

main()
{
	int fd;
	int r;
	struct sockaddr_in addr;
	char buf[100];
	fd_set fds;
	
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd==-1) printf("1:%m\n"),exit(-1);
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	addr.sin_addr.s_addr = inet_addr("172.16.34.56");

	r = connect(fd,(struct sockaddr*)&addr,sizeof(addr));
	if(r==-1) printf("2:%m\n"),exit(-1);

	while(1)
	{
		FD_ZERO(&fds);
		FD_SET(fd,&fds);
		select(fd+1,0,&fds,0,0);
		send(fd,"Hello",5,MSG_OOB);
	}
	close(fd);
}
