/*************************************************************************
	> File Name: wr_fifo.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/22 15:16:54 2014
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define N 1024

int main(int argc, char *argv[])
{
	if (-1 == mkfifo(argv[2], 0666)) {
		perror("mkfifo2");
		exit(1);
	}
	int fd1 = open(argv[1], O_WRONLY);
	if (fd1 < 0) {
		perror("open fifo1");
		exit(1);
	}
	int fd2 = open(argv[2], O_RDONLY);
	if (fd2 < 0) {
		perror("open fifo2");
		exit(1);
	}
	printf("open fifo success.\n");
	char buf1[N];
	char buf2[N];
	int flag1 = 0;
	int flag2 = 0;
	while (!flag1 && !flag2) {
		memset(buf1, 0, N); 
		fflush(stdin);
		fflush(stdout);
		if ((flag1 == 0) && (fgets(buf1, N, stdin) == NULL)) {
			flag1 = 1;
			close(fd1);
		} else if (flag1 == 0){
			write(fd1, buf1, strlen(buf1));
		}

		memset(buf2, 0, N);
		if ((flag2 == 0) && (read(fd2, buf2, N) == 0)) {
			flag2 = 1;
		} else if (flag2 == 0) {
			write(1, buf2, strlen(buf2));
		}
	}
	unlink(argv[2]);
	return 0;
}
