/************************************************************************
	> File Name: open_fifo.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/22 15:10:12 2014
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
	int flag1 = 0;
	int flag2 = 0;
	while (!flag1 || !flag2) {
		memset(buf1, 0, N);
		if ((read(fd1, buf1, N) == 0) && (flag1 == 0)) {
			flag1 = 1;
		} else if (flag1 == 0) {
			write(1, buf1, strlen(buf1));
		}

		memset(buf2, 0, N);
		fflush(stdin);
		fflush(stdout);
		if ((fgets(buf2, N, stdin) == NULL) && (flag2 == 0)) {
			flag2 = 1;
			close(fd2);
		} else if (flag2 == 0) {
			write(fd2, buf2, strlen(buf2));
		}
	}
	unlink(argv[1]);
	return 0;
}
