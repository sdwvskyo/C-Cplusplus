/************************************************************************
	> File Name: 1.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/22 21:24:04 2014
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define N 1024
int main(int argc, char *argv[])
{
	if (mkfifo(argv[1], 0666) < 0 || mkfifo(argv[2], 0666) < 0) {
		perror("mkfifo");
		exit(1);
	}
	int fd_12 = open(argv[1], O_WRONLY);
	int fd_13 = open(argv[2], O_WRONLY);
	int fd_21 = open(argv[3], O_RDONLY);
	int fd_31 = open(argv[4], O_RDONLY);
	if (fd_12 < 0 || fd_13 < 0 || fd_21 < 0 || fd_31 < 0) {
		perror("open fifo");
		exit(1);
	}
	printf("PIPE open success!\n");
	char buf[N];
	if (fork() == 0) {
		close(fd_12);
		close(fd_13);
		close(fd_31);
		while(memset(buf, 0, N), read(fd_21, buf, N) > 0) {
			write(1, buf, strlen(buf));
		}
		close(fd_21);
		exit(1);
	}
	if (fork() == 0) {
		close(fd_12);
		close(fd_13);
		close(fd_21);
		while(memset(buf, 0, N), read(fd_31, buf, N) > 0) {
			write(1, buf, strlen(buf));
		}
		close(fd_31);
		exit(1);
	}
	close(fd_21);
	close(fd_31);
	while (memset(buf, 0, N), fgets(buf, N, stdin) != NULL) {
		write(fd_12, buf, strlen(buf));
		write(fd_13, buf, strlen(buf));
	}
	close(fd_12);
	close(fd_13);

	wait(NULL);
	wait(NULL);
	unlink(argv[1]);
	unlink(argv[2]);
	printf("1 done!\n");
	return 0;
}
