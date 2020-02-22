#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

main()
{
	int fd;	//socket描述符号
	struct sockaddr_in ad;//本机的ip地址
	char buf[100];//接受数据的缓冲
	struct sockaddr_in ad_snd;//发送者的ip地址
	socklen_t len;//发送者IP的长度
	int r;
	
	fd=socket(AF_INET,SOCK_DGRAM,17);
	if(fd==-1) printf("sockete:%m\n"),exit(-1);
	printf("建立socket成功！\n");

	ad.sin_family=AF_INET;
	ad.sin_port=htons(11111);
	inet_aton("127.0.0.1",&ad.sin_addr);
	r=bind(fd,(struct sockaddr*)&ad,sizeof(ad));
	if(r==-1) printf("bind err:%m\n"),exit(-1);
	printf("绑定成功！\n");
	
	while(1)
	{
		len = sizeof(ad_snd);
		r=recvfrom(fd,buf,sizeof(buf)-1,0,
			(struct sockaddr*)&ad_snd,&len);
		if(r>0)
		{
			buf[r]=0;
			printf("发送者IP:%s,端口:%hu,数据：%s\n",
				inet_ntoa(ad_snd.sin_addr),
				ntohs(ad_snd.sin_port),buf);
			sendto(fd,"古怪！",strlen("古怪！"),0,
				(struct sockaddr*)&ad_snd,sizeof(ad_snd));
		}
		if(r==0)
		{
			printf("关闭！\n");
			break;
		}
		if(r==-1)
		{
			printf("网络故障!\n");
			break;
		}
	}
	close(fd);

}
