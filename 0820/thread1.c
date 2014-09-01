/*************************************************************************
	> File Name: thread1.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  8/20 22:04:30 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void *thread_function(void *arg);

char message[] = "Hello world";

int main(int argc, char *argv[])
{
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
	if (res != 0) {
		perror("thread create error");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for thread to finish....\n");
	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
		perror("thread join");
		exit(EXIT_FAILURE);
	}
	printf("thread joined, it returned %s\n", (char *)thread_result);
	printf("message is now: %s", message);
	exit(EXIT_SUCCESS);

	return 0;
}

void *thread_function(void *arg)
{
	printf("Thread is startiing, with argument %s\n", (char *)arg);
	sleep(3);
	strcpy(message, "Bye!\n");
	pthread_exit("Thank you for CPU time.\n");
}
