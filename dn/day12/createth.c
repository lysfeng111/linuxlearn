#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
void call()
{
	pthread_exit("Kill");
	return ;
}
void* run(void* data)
{
	while(1)
	{
		printf("我是线程！%s\n",data);
		sched_yield();
		//return "hello";
		pthread_exit("world");
	}
}

main()
{
	pthread_t tid;
	char *re;
	pthread_create(&tid,0,run,"Jack");
	pthread_join(tid,(void**)&re);
	printf("%s\n",re);
}
