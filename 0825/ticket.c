/*************************************************************************
	> File Name: ticket.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  8/25 19:11:28 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int ticket = 50;

typedef struct tag {
	int id;
	pthread_mutex_t *pMutex;
} Data;

void *handle(void *arg)
{
	int id = ((Data *)arg)->id;
	pthread_mutex_t *pMutex = ((Data *)arg)->pMutex;
	printf("%d on: \n", id);
	while (1) {
		pthread_mutex_lock(pMutex);
		if (ticket != 0) {
			ticket--;
			printf("windows %d sold one ticket, %d left\n", id, ticket);
			pthread_mutex_unlock(pMutex);
			sleep(rand() % 3 + 1);
		} else {
			printf("ticket is out!\n");
			pthread_mutex_unlock(pMutex);
			free((Data *)arg);
			return (void *)0;
		}
	}
	free((Data *)arg);
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		perror("argc");
		exit(1);
	}
	srand(time(NULL));
	int n = atoi(argv[1]);
	int res;
	pthread_mutex_t mutex;
	res = pthread_mutex_init(&mutex, NULL);
	if (res < 0) {
		perror("mutex init");
		exit(1);
	}
	pthread_t *th = (pthread_t *)calloc(n, sizeof(pthread_t));
	if (th == NULL) {
		perror("pthread_t calloc");
		exit(1);
	}
	int i;
	for (i = 0; i < n; i++) {
		Data *data =(Data *)calloc(1, sizeof(Data));
		if (data == NULL) {
			perror("calloc");
			exit(1);
		}
		data->id = i;
		data->pMutex = &mutex;
		res = pthread_create(th + i, NULL, handle, data);
		if (res < 0) {
			perror("pthread create");
			exit(1);
		}
	}
	printf("working on!\n");
	void *ret[n];
	for (i = 0; i < n; i++) {
		res = pthread_join(th[i], &ret[i]);
		if (res < 0) {
			perror("pthread join");
			exit(1);
		}
		printf("%d off\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("Done!\n");
	return 0;
}
