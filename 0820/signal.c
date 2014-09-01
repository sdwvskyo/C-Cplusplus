/*************************************************************************
	> File Name: signal.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  8/20 20:35:31 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <signal.h>

void ouch(int sig)
{
	printf("OUCH, I got a signal: %d\n", sig);
	(void) signal(SIGINT, SIG_DFL);
}

int main(int argc, char *argv[])
{
	(void) signal(SIGINT, ouch);

	while (1) {
		printf("Hello world!\n");
		sleep(1);
	}
	return 0;
}
