/*==================================================
	@title:socket client example

int socket(int protofamily, int type, int protocol)
param:
     protofamily: AF_INET(IPV4)、AF_INET6(IPV6)
     type:SOCK_STREAM、SOCK_DGRAM、SOCK_RAW、SOCK_PACKET、SOCK_SEQPACKET
     protocol:IPPROTO_TCP、IPPTOTO_UDP、IPPROTO_SCTP、IPPROTO_TIPC  (0 for default)
===================================================*/
#include<stdio.h>
#include<string.h>
#include <netinet/in.h>   //for sockaddr_in
int main()
{
	int sockfd, n, rec_len;
	char ip[10];
	struct sockaddr_in servaddr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&servaddr, 0, sizeof(servaddr));  

	servaddr.sin_family = AF_INET;  
        servaddr.sin_port = htons(8888); 
	printf("Ip address:\n");
	scanf("%s",ip);
	inet_pton(AF_INET,ip, &servaddr.sin_addr); 
        connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)); 
}
