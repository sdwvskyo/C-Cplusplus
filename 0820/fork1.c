/*************************************************************************
	> File Name: fork1.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  8/20 16:18:30 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	pid_t pid;
	printf("Hello world! %u\n", getpid());
	pid = fork();
	if (pid == 0) {
		printf("This is child: %u, pid = %u, ppid = %u\n", getpid(), pid, getppid());
	} else if (pid > 0){
		printf("This is parent: %u, pid = %u, ppid = %u\n", getpid(), pid, getppid());
	} else {
		perror("fork");
		exit(1);
	}
	printf("bye.%u\n", getpid());
	return 0;
}
