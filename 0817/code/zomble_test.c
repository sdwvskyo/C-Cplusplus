/*************************************************************************
	> File Name: zomble_test.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  8/17 11:13:18 2014
 ************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	pid_t pid = fork();
	if (pid < 0) {
		perror("fork");
		exit(1);
	}
	if (pid > 0) {
		while(1);
	}

	return 0;
}

