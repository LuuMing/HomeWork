#include<stdio.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd = open("/dev/whoami",O_RDONLY);
	char buf[1024];
	int ret = read(fd,buf,1024);
	printf("%d %s",ret, buf);
	getchar();
}
