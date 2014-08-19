/*************************************************************************
	> File Name: alarm.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/19 22:03:36 2014
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static int alarm_fired = 0;

void ding(int sig)
{
	alarm_fired = 1;
}

int main(int argc, char *argv[])
{
	pid_t pid;
	printf("program starting:\n");
	pid = fork();
	switch(pid) {
		case -1:
			perror("folk failed");
			exit(1);
		case 0:
			sleep(3);
			kill(getppid(), SIGALRM);
			exit(0);
	}

	printf("Waiting for alarm to go:\n");
	(void) signal(SIGALRM, ding);
	pause();

	if(alarm_fired) 
		printf("ding!\n");

	printf("Done!\n");
	exit(0);
	return 0;
}

