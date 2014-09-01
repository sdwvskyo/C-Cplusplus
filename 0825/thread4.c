/*************************************************************************
	> File Name: thread4.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  8/25 20:28:56 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 1024

pthread_mutex_t mutex;
char buf[N] = "";
int time_to_exit = 0;

void *handle(void *arg)
{
	sleep(1);
	pthread_mutex_lock(&mutex);
	while (strncmp("end", buf, 3) != 0) {
		printf("you input %lu charactors\n", strlen(buf) - 1);
		buf[0] = '\0';
		pthread_mutex_unlock(&mutex);
		sleep(1);
		pthread_mutex_lock(&mutex);
		while (buf[0] == '\0') {
			pthread_mutex_unlock(&mutex);
			sleep(1);
			pthread_mutex_lock(&mutex);
		}
	}
	time_to_exit = 1;
	buf[0] = '\0';
	pthread_mutex_unlock(&mutex);
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	int res;
	pthread_t th;
	res = pthread_mutex_init(&mutex, NULL);
	if (res != 0) {
		perror("Mutex init");
		exit(EXIT_FAILURE);
	}
	res = pthread_create(&th, NULL, handle, NULL);
	if (res != 0) {
		perror("thread create");
		exit(EXIT_FAILURE);
	}
	pthread_mutex_lock(&mutex);
	while (!time_to_exit) {
		printf ("Input string: \n");
		fgets(buf, N, stdin);
		pthread_mutex_unlock(&mutex);
		while (1) {
			pthread_mutex_lock(&mutex);
			if (buf[0] != '\0') {
				pthread_mutex_unlock(&mutex);
				sleep(1);
			} else {
				break;
			}
		}
	}
	pthread_mutex_unlock(&mutex);
	printf("waiting for thread to end...");
	void *ret;
	res = pthread_join(th, &ret);
	if (res != 0) {
		perror("join failure");
		exit(EXIT_FAILURE);
	}
	pthread_mutex_destroy(&mutex);
	return 0;
}
