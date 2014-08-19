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

int main(int argc, char *argv[])
{
	if (argc < 2) {
		perror("argc: ");
		exit(1);
	}

	int fd = open(argv[1], O_RDONLY | O_CREAT, 0777);
	if (fd < 0) {
		perror("open file: ");
		exit(1);
	}

	close(fd);
	return 0;
}

