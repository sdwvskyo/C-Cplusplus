/*************************************************************************
	> File Name: fork1.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/22 19:52:30 2014
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define N 1024

int main(int argc, char *argv[])
{
	if (-1 == mkfifo(argv[1], 0666)) {
		perror("mkfifo1");
		exit(1);
	}
	printf("mkfifo seccess!\n");
	int fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0) {
		perror("open fifo");
		exit(1);
	}
	int fd2 = open(argv[2], O_WRONLY);
	if (fd2 < 0) {
		perror("open fifo2");
		exit(1);
	}
	printf("open fifo success.\n");
	char buf1[N];
	char buf2[N];
	if (fork() == 0) {
		close(fd2);
		while (memset(buf1, 0, N), read(fd1, buf1, N) > 0) {
			write(1, buf1, strlen(buf1));
		}
	} else {
		close(fd1);
		while (memset(buf2, 0, N), fgets(buf2, N, stdin) != NULL) {
			write(fd2, buf2, N);
		}
		close(fd2);
		wait(NULL);
	}
	unlink(argv[1]);
	return 0;
}
