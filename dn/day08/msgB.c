#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf{
	long mtype;
	char mtext[32];
};
main()
{
	int msgid;
	key_t key;
	//1.得到消息队列
	key = ftok(".",200);
	if(key == -1) printf("ftok error:%m\n"),exit(-1);
	
	msgid = msgget(key,0);
	if(msgid == -1) printf("msgget error:%m\n"),exit(-1);
	//2.构造消息
	struct msgbuf buf;
	//3.接受消息
	while(1)
	{
		bzero(&buf,sizeof(buf));
		buf.mtype = 2;
		msgrcv(msgid,&buf,sizeof(buf.mtext),2,0);
		
		printf("%s\n",buf.mtext);
	}
}
