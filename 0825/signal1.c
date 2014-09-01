/*************************************************************************
	> File Name: signal.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  8/25 10:06:56 2014
 ************************************************************************/

#include<stdio.h>
#include <signal.h>

void fun(int n)
{
	printf("Get a signal: %d", n);
}

int main(int argc, char *argv[])
{
	signal(SIGINT, fun);
	signal(SIGQUIT, fun);
	int n;
	while (scanf("%d", &n) == 1) {
		printf("Hello world!\n");
	}
	return 0;
}
