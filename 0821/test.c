
/*************************************************************************
	> File Name: pipe.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  8/21 21:25:57 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define N 1024

int main(int argc, char *argv[])
{
	int fd1[2];

	if (pipe(fd1) < 0) {
		perror("pipe");
		exit(1);
	}

	pid_t pid = fork();
	if (pid < 0) {
		perror("fork error");
		exit(1);
	} 

	if (pid == 0) {
		close(fd1[0]);
		char buf[N];
		while (memset(buf, 0, N), read(fd1[1], buf, N) != 0) {
			printf("Child read: %s", buf);
		}
		printf("child exit\n");
		exit(0);
	} else {
		close(fd1[1]);
		char str[N];
		while (fflush(stdin), fgets(str, N, stdin) != NULL) {
			write(fd1[0], str, strlen(str));
		}
		close(fd1[0]);
		wait(NULL);
	}
	return 0;
}
