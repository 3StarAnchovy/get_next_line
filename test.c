#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#define	BUFF_SIZE 1024


int main(void)
{
	int fd;
	char buff[BUFF_SIZE];

	fd = open("./test.txt",O_RDONLY);
	printf("%d",fd);
	if (fd > 0)
	{
		printf("%zd",read(fd,buff,BUFF_SIZE));
		puts(buff);
		close(fd);
	}
	else
		printf("fail");
}
