/*************************************************************************
	> File Name: client.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/23 15:21:57 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define N 1024

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_WRONLY);
	if (fd < 0) {
		perror("open file ");
		exit(1);
	}
	printf("clisent success!\n");
	char buf[N];
	while (memset(buf, 0, N), fgets(buf, N, stdin) != NULL) {
		write(fd, buf, strlen(buf));
	}
	close(fd);
	return 0;
}

