#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

main()
{
	int serverfd;
	int cfd;
	struct sockaddr_in sadr;
	struct sockaddr_in cadr;
	int r;
	char buf[1024];
	socklen_t len;
	//1.socket
	serverfd = socket(AF_INET,SOCK_STREAM,0);
	if(serverfd == -1) printf("1:%m\n"),exit(-1);
	printf("建立服务器socket成功！\n");
	//2.bind
	sadr.sin_family=AF_INET;
	sadr.sin_port=htons(9999);
	//inet_aton("172.16.34.56",&sadr.sin_addr);
	sadr.sin_addr.s_addr = htonl(INADDR_ANY);	

	r=bind(serverfd,(struct sockaddr*)&sadr,sizeof(sadr));
	if(r==-1) printf("2:%m\n"),exit(-1);
	printf("服务器地址绑定成功！\n");
	
	//3.listen
	r = listen(serverfd,10);
	if(r==-1) printf("3:%m\n"),exit(-1);
	printf("监听服务器成功！\n");

	//4.accept
	while(1)
	{
		len=sizeof(cadr);
		cfd=accept(serverfd,(struct sockaddr*)&cadr,&len);
		printf("有人连接：%d，IP：%s:%u\n",cfd,inet_ntoa(cadr.sin_addr),
					ntohs(cadr.sin_port));
		//5.处理代理客户描述符号的数据u
		r = recv(cfd,buf,100,0);
		if(r>0)
		{
			buf[r]=0;
			printf("::%s\n",buf);
		}
		
		if(r==0)
		{
			printf("连接断开！\n");
		}
		if(r==-1)
		{
			printf("网络故障！\n");
		}
		
	}
	close(serverfd);
	close(cfd);
}
