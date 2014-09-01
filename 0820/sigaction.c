/*************************************************************************
	> File Name: sigaction.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  8/20 21:14:46 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void ouch(int sig)
{
	printf("OUCH, I got a signal. %d\n", sig);
}

int main(int argc, char *argv[])
{
	struct sigaction act;
	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, NULL);

	while (1) {
		printf("hello world.\n");
		sleep(1);
	}
	return 0;
}
