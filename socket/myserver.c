#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
	int listenfd, connfd;
	struct sockaddr_in sockaddr;

	memset(&sockaddr, 0, sizeof(sockaddr));

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	sockaddr.sin_port = htons(8888);
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	
	bind(listenfd, (struct sockaddr *) & sockaddr, sizeof(sockaddr));
	listen(listenfd, 1024);

	while(1)
	{
		if( (connfd = accept(listenfd, (struct sockaddr*)NULL,NULL)) == -1)
		{
			printf("-");
		}
		else
		{
			printf("success!");
			break;
		}
	}
	
}
