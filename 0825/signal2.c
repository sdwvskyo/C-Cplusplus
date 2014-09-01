/*************************************************************************
	> File Name: signal2.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  8/25 11:14:00 2014
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define N 1024

void handle(int n)
{
	printf("Get a signal: %d\n", n);
	wait(NULL);
}

int main(int argc, char *argv[])
{
	int fds[2];
	int res;
	res = pipe(fds);
	if (res < 0) {
		perror("pipe");
		exit(1);
	}
	char buf[N];
	signal(SIGPIPE, handle);
	signal(SIGCHLD, handle);

	if (fork() == 0) {
		close(fds[1]);
		while (memset(buf, 0, N), read(fds[0], buf, N)) {
			write(1, buf, strlen(buf));
		}
		printf("child over!\n");
		close(fds[0]);
		exit(0);
	}

	if (fork() == 0) {
		exit(0);
	}
	close(fds[0]);
	while (memset(buf, 0, N), fgets(buf, N, stdin) != NULL) {
		res = write(fds[1], buf, strlen(buf));
		if (res == 0) {
			perror("write");
			exit(1);
		}
	}
	close(fds[1]);
	sleep(3);
	return 0;
}

