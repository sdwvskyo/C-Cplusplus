/*************************************************************************
	> File Name: fork.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  8/24 14:35:44 2014
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

int wib(int no1, int no2)
{
	int result, diff;
	diff = no1 - no2;
	result = no1 / diff;
	return result;
}

int main(void)
{
	pid_t pid;
	pid = fork();
	if (pid < 0) {
		perror("fork ");
		exit(1);
	} else if (pid == 0) {
		sleep(60);
		int value = 10;
		int div = 6;
		int total = 0;
		int i = 0;
		int result = 0;
		for (i = 0; i < 10; i++) {
			result = wib(value, div);
			total += result;
			div++;
			value--;
		}
		printf("%d wibed by %d equals %d\n", value, div, total);
		exit(0);
	} else {
		sleep(4);
		wait((int *)-1);
		exit(0);
	}
}
