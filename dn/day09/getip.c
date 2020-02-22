#include <stdio.h>
#include <netdb.h>

main()
{
	struct hostent *ent;
	ent = gethostbyname("www.wanqile.com");
	printf("%s\n",ent->h_aliases[0]);
	size_t size = sizeof(ent->h_addr_list)/sizeof(ent->h_addr_list[0]);
	int n;
	for(n=0;n<size;n++)
	{
	printf("%hhu.%hhu.%hhu.%hhu\n",
		ent->h_addr_list[n][0],ent->h_addr_list[n][1],ent->h_addr_list[n][2],ent->h_addr_list[n][3]);
	}
}
