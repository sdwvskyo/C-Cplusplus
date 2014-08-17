/*************************************************************************
	> File Name: fork.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  8/17 10:06:22 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	char *message;
	int n;
	pid = fork();
	if (pid < 0) {
		perror("fork failed");
		exit(1);
	}
	if (pid == 0) {
		message = "This is child.\n";
		n = 6;
	} else {
		message = "This is the parent.\n";
		n = 3;
	}
	for(; n > 0; n--) {
		printf("%s", message);
		sleep(1);
	}
	return 0;
}

