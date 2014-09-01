/*************************************************************************
	> File Name: thread2.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  8/20 22:22:54 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *pthread_func(void *arg);

int run_now = 1;

int main(int argc, char *argv[])
{
	pthread_t a_thread;
	int res;
	void *thread_result;
	res = pthread_create(&a_thread, NULL, pthread_func, NULL);
	if (res != 0) {
		perror("thread creat failure");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for thread finish....\n");
	int cnt1 = 0;
	while (cnt1++ < 20) {
		if (run_now == 1) {
			printf("1\n");
			run_now = 2;
		} else {
			sleep(1);
		}
	}
	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
		perror("thread join failure");
		exit(EXIT_FAILURE);
	}

	printf("Done!\n");
	exit(EXIT_SUCCESS);
	return 0;
}

void *pthread_func(void *arg)
{
	int cnt2 = 0;
	while (cnt2++ < 20) {
		if (run_now == 2) {
			printf("2\n");
			run_now = 1;
		} else {
			sleep(1);
		}
	}
	exit(EXIT_SUCCESS);
}
