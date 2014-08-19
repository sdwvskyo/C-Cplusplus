
/*************************************************************************
	> File Name: my_write.c
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
	if (argc < 3) {
		perror("argc: ");
		exit(1);
	}
	
	int fd = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_WRONLY | O_CREAT, 0666);
	if (fd < 0 || fd2 < 0) {
		perror("open file: ");
		exit(1);
	}

	char buf[128];
	int cnt;
	int cnt2;
	while (memset(buf, 0, 127), cnt = read(fd, buf, 127)) {
		printf("read: %d:", cnt);
		cnt2 = write(fd2, buf, cnt);
		printf("write: %d", cnt2);
	}
	close(fd2);
	close(fd);
	return 0;
}

