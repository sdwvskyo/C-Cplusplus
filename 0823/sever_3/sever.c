/************************************************************************
	> File Name: sever.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/23 14:40:24 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/select.h>
#include <fcntl.h>
#include <unistd.h>

#define N 1024

int main(int argc, char *argv[]) 
{
	int fd1 = open(argv[1], O_RDONLY | O_NONBLOCK);
	int fd2 = open(argv[2], O_RDONLY | O_NONBLOCK);
	int fd3 = open(argv[3], O_RDONLY | O_NONBLOCK);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0) {
		perror("open fifo");
		exit(1);
	}
	printf("server success!\n");

	fd_set set, back;
	FD_ZERO(&back);
	FD_SET(fd1, &back);
	FD_SET(fd2, &back);
	FD_SET(fd3, &back);
	struct timeval tm;
	tm.tv_sec = 10;
	tm.tv_usec = 0;
	char buf[N];
	while (1) {
		set = back;
		if (select(6, &set, NULL, NULL, &tm) <= 0) {
			printf("time out!\n");
			continue;
		}
		if (FD_ISSET(fd1, &set)) {
			memset(buf, 0, N);
			if (read(fd1, buf, N) != 0) {
				write(1, buf, strlen(buf));
			} else {
				printf("fd1 exit!\n");
				FD_CLR(fd1, &set);
			}
		}
		if (FD_ISSET(fd2, &set)) {
			memset(buf, 0, N);
			if (read(fd2, buf, N) != 0) {
				write(1, buf, strlen(buf));
			} else {
				printf("fd2 exit\n");
				FD_CLR(fd2, &set);
			}
		}
		if (FD_ISSET(fd3, &set)) {
			memset(buf, 0, N);
			if (read(fd3, buf, N) != 0) {
				write(1, buf, strlen(buf));
			} else {
				printf("fd3 eixt\n");
				FD_CLR(fd3, &set);
			}
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;

}
