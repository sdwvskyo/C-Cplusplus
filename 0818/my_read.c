/*************************************************************************
	> File Name: my_read.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  8/18 10:50:49 2014
 ************************************************************************/

#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		perror("argc: ");
		exit(1);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror("open file: ");
		exit(1);
	}

	char buf[128];
	int cnt;
	while (memset(buf, 0, 127), cnt = read(fd, buf, 127)) {
		printf("read: %d: %s", cnt, buf);
	}
	printf("cnt = %d.\n", cnt);
	close(fd);
	return 0;
}

