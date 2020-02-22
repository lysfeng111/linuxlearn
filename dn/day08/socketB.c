#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <linux/un.h>
#include <string.h>
#include <unistd.h>
main()
{
	int fd;
	int r;
	struct sockaddr_un addr={0};
	//1.建立socket
	fd=socket(AF_UNIX,SOCK_DGRAM,0);
	//2.连接到指定的地址
	addr.sun_family = AF_UNIX;
	memcpy(addr.sun_path,"my.sock",strlen("my.sock"));
	r = connect(fd,(struct sockaddr*)&addr,sizeof(addr));
	//3.发送数据
	write(fd,"Hello!Maomaochong!",strlen("Hello!Maomaochong!"));
	//4.关闭
	close(fd);
}
