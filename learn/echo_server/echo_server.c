#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <errno.h>

#define SERVER_PORT 80 

perror_exit(const char* des){
        fprintf(stderr, "%s error, reason: %s\n",des, strerror(errno));
        exit(1);
}

int get_line(int sock, char *buf, int size);

int main(void)
{
	int sock;//代表信箱
	int i,ret;
	struct sockaddr_in server_addr; // 服务器地址

	//创建信箱
	sock = socket(AF_INET,SOCK_STREAM,0);//网络通信家族，TCP

	if(sock == -1)
	{
		perror_exit("create socket");
	}
	
	//先清空标签，写上地址和端口号
	bzero(&server_addr,sizeof(server_addr));
	
	server_addr.sin_family = AF_INET; //选择协议族IPV4
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY); //监听本地所有IP地址
	server_addr.sin_port = htons(SERVER_PORT);//绑定端口号


	//实现标签贴到信箱上
	ret = bind(sock,(struct sockaddr *)&server_addr, sizeof(server_addr));
	if(ret == -1)
	{
		perror_exit("bind");
	}
	
	//吧信箱挂置到传达室，这样，就可以接受信件了
	ret = listen(sock,128 );
	if(ret == -1)
        {
		perror_exit("listen");
        }	

	printf("等待客户端的连接\n");
	

	int done = 1;
	while(done)
	{
		struct sockaddr_in client;
		int client_sock,len;
		char client_ip[64];
		char buf[256];

		socklen_t client_addr_len;
		client_addr_len = sizeof(client);

		client_sock = accept(sock,(struct sockaddr *)&client, &client_addr_len);

		//打印客户端口地址和端口号
		printf("client ip: %s\t port : %d\n",
			inet_ntop(AF_INET, &client.sin_addr.s_addr,client_ip,sizeof(client_ip)),
			ntohs(client.sin_port));
		/*读取客户端发送的请求数据*/
		do{
			int len = get_line(client_sock,buf,sizeof(buf));
			printf("read line: %s\n", buf);
		}while(len>0);

		

		len = write(client_sock, buf, len);
		printf("write finished. len: %d\n", len);
	
		close(client_sock);
	}
close(sock);
	return 0;
}


int get_line(int sock, char *buf, int size){

	int count = 0;
	char ch = '\0';
	int len = 0;

	
	while((count<size-1) && ch != '\n'){
		len = read(sock, &ch, 1);
		
		if(len == 1){
		    if(ch == '\r'){
			continue;
		    }else if(ch == '\n'){
			buf[count] = '\0';
			break;
		    }		

		    buf[count] = ch;
		    count ++;
		}
	
	}
	return count;
}
