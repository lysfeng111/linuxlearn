#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>



int main(void)
{
char ip[] = "2.3.4.5";
char server_ip[64];

struct sockaddr_in server_addr;

inet_pton(AF_INET, ip, &server_addr.sin_addr.s_addr);

printf("s_addr : %x\n", server_addr.sin_addr.s_addr);
printf("s_addr from net to host: %x\n", ntohl(server_addr.sin_addr.s_addr));

inet_ntop(AF_INET, &server_addr.sin_addr.s_addr, server_ip, 64);

printf("server ip : %s\n",server_ip);

printf("INADDR_ANY: %s\n", INADDR_ANY);

server_addr.sin_addr.s_addr = INADDR_ANY;
inet_ntop(AF_INET, &server_addr.sin_addr.s_addr, server_ip, 64);
printf("INADDR_ANY ip : %s\n", server_ip);

return 0;

}
