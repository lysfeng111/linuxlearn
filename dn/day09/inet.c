#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

main()
{
	/*
	in_addr_t nip= 192<<23 | 168<<16 | 0<<8 | 26;
	char *ip = "192.168.0.26";
	//char cip[4]={192,168,0,26};
	//int  *nip2=(int*)cip;
	//把整数转换为字符串 inet_ntoa
	struct in_addr sip={nip};
	int myip;

	printf("%s\n",inet_ntoa(sip));

	myip = inet_addr(ip);
	printf("%u\n",myip);
	printf("%u.%u.%u.%u\n",myip>>24 & 255,myip>>16 & 255, myip>>8 & 255, myip>>0 & 255);
	*/
	/*
 	char ip[4] = {192,168,0,26};
	printf("%d\n",*(int*)ip);
 	*/
	char *ip = "47.107.189.4";
	struct in_addr addr;
	in_addr_t net;
	in_addr_t host;	
	struct in_addr tmp;

	inet_aton(ip,&addr);
	net = inet_lnaof(addr);
	host = inet_netof(addr);
	tmp.s_addr = net;
	printf("%s\n",inet_ntoa(tmp));
	tmp.s_addr=host;
	printf("%s\n",inet_ntoa(tmp));
}
