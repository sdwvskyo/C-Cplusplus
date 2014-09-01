/*************************************************************************
	> File Name: 3.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/22 21:46:01 2014
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
	if (mkfifo(argv[2], 0666) < 0 || mkfifo(argv[4], 0666) < 0) {
		perror("mkfifo");
		exit(1);
	}
	int fd_13 = open(argv[1], O_RDONLY);
	int fd_31 = open(argv[2], O_WRONLY);
	int fd_23 = open(argv[3], O_RDONLY);
	int fd_32 = open(argv[4], O_WRONLY);
	if (fd_13 < 0 || fd_31 < 0 || fd_23 < 0 || fd_32 < 0) {
		perror("open fifo");
		exit(1);
	}
	printf("PIPE open success!\n");
	char buf[N];
	if (fork() == 0) {
		close(fd_13);
		close(fd_31);
		close(fd_32);
		while(memset(buf, 0, N), read(fd_23, buf, N) > 0) {
			write(1, buf, strlen(buf));
		}
		close(fd_23);
		exit(1);
	}
	if (fork() == 0) {
		close(fd_23);
		close(fd_32);
		close(fd_31);
		while(memset(buf, 0, N), read(fd_13, buf, N) > 0) {
			write(1, buf, strlen(buf));
		}
		close(fd_13);
		exit(1);
	}
	close(fd_13);
	close(fd_23);
	while (memset(buf, 0, N), fgets(buf, N, stdin) != NULL) {
		write(fd_31, buf, strlen(buf));
		write(fd_32, buf, strlen(buf));
	}
	close(fd_31);
	close(fd_32);

	wait(NULL);
	wait(NULL);
	unlink(argv[2]);
	unlink(argv[4]);
	printf("3 done!\n");
	return 0;
}
