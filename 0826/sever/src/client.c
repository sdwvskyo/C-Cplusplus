/*************************************************************************
	> File Name: client.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/26 21:13:49 2014
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define N 1024

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("argument less\n");
		exit(1);
	}
	//open sever fifo by write
	pid_t pid = getpid();
	int fd_sever = open(argv[1], O_WRONLY);
	if (fd_sever < 0) {
		perror("open fd_sever");
		exit(1);
	}
	printf("connect sever!\n");
	//send conenct message
	char buf[N];
	memset(buf, 0, N);
	sprintf(buf, "%d", pid);
	write(fd_sever, buf, strlen(buf));
	
	//make send and receive fifos and open them
	char buf1[N];
	memset(buf1, 0, N);
	sprintf(buf1, "r.%d", pid);
	char buf2[N];
	memset(buf2, 0, N);
	sprintf(buf2, "w.%d", pid);

	if (mkfifo(buf1, 0666) != 0) {
		perror("mkfifo");
		exit(1);
	}
	if (mkfifo(buf2, 0666) != 0) {
		perror("mkfifo");
		exit(1);
	}

	int fd_recv = open(buf1, O_RDONLY);
	if (fd_recv < 0) {
		perror("open recvfifo");
		exit(1);
	}
	printf("Receive connect!\n");

	int fd_send = open(buf2, O_WRONLY);
	if (fd_send < 0) {
		perror("open send");
		exit(1);
	}
	printf("Send connect!\n");

	//Send task
	while (memset(buf, 0, N), fgets(buf, N, stdin)) {
		if (write(fd_send, buf, strlen(buf)) <= 0) {
			printf("write error!\n");
		}
		memset(buf, 0, N);
		if (read(fd_recv, buf, N) == 0) {
			break;
		}
		write(1, buf, strlen(buf));
	}
	
	close(fd_recv);
	close(fd_send);
	close(fd_sever);
	unlink(buf1);
	unlink(buf2);
	printf("log off!\n");
	return 0;
}
