/************************************************************************
	> File Name: client.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/23 20:07:56 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define N 1024

int main(int argc, char *argv[])
{
	int fd_send = open(argv[1], O_WRONLY);
	if (fd_send < 0) {
		perror("open fifo");
		exit(1);
	}
	int pid = getpid();
	char name[N];
	memset(name, 0, N);
	sprintf(name, "%d.fifo", pid);
	if (mkfifo(name, 0666) < 0) {
		perror("mkfifo");
		exit(1);
	}

	char buf[N];
	memset(buf, 0, N);
	sprintf(buf, "on_%d", pid);
	if (write(fd_send, buf, strlen(buf)) > 0) {
		printf("%d on\n", pid);
	} else {
		printf("send on fail\n");
	}

	int fd_recv = open(name, O_RDONLY);
	if (fd_recv < 0) {
		perror("open fifo");
		exit(1);
	}

	if (fork() == 0) {
		close(fd_send);
		while (memset(buf, 0, N), read(fd_recv, buf, N) > 0) {
			write(1, buf, strlen(buf));
		}
		close(fd_recv);
		exit(1);
	}	

	close(fd_recv);
	while (memset(buf, 0, N), fgets(buf, N, stdin) != NULL) {
		write(fd_send, buf, strlen(buf));
	}
	memset(buf, 0, N);
	sprintf(buf, "off_%d", pid);
	write(fd_send, buf, strlen(buf));
	close(fd_send);
	wait(NULL);
	unlink(name);
	printf("%d off\n", pid);
	return 0;
}
