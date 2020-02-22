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
	int type = 1;
	struct sockaddr_in addr;
	
	fd = socket(AF_INET,SOCK_DGRAM,0);
	if(fd==-1) printf("1:%m\n"),exit(-1);
	
	r = setsockopt(fd,SOL_SOCKET,SO_BROADCAST,&type,sizeof(type));

	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	addr.sin_addr.s_addr = inet_addr("172.16.63.255");

	sendto(fd,"Hell0",sizeof("Hello"),0,(struct sockaddr*)&addr,sizeof(addr));
}
