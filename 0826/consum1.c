/*************************************************************************
	> File Name: consum1.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/26 14:41:35 2014
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define N 21

typedef struct tag {
	int ar[N];
	int front;
	int rear;
} Quene;

Quene quene;

int isFull(Quene *q)
{
	return (q->rear + 1) % N == q->front;
}
int isEmpty(Quene *q)
{
	return q->rear == q->front;
}
int queneSize(Quene *q)
{
	return (q->rear + N - q->front) % N;
}

pthread_mutex_t mutex;
pthread_cond_t cond_pro;
pthread_cond_t cond_con;

void cleanup_handler(void *arg)
{
	printf("Cleanup handle of second thread\n");
	pthread_mutex_unlock(&mutex);
}

void *produce(void *arg)
{
	pthread_detach(pthread_self());
	pthread_cleanup_push(cleanup_handler, NULL);
	while (1) {
		pthread_mutex_lock(&mutex);
		while (isFull(&quene)) {
			pthread_cond_wait(&cond_con, &mutex);
		}
		quene.rear = (quene.rear + 1) % N;
		printf("produce: %d\n", queneSize(&quene));
		pthread_mutex_unlock(&mutex);
		if (queneSize(&quene) == 1) {
			pthread_cond_broadcast(&cond_pro);
		}
		sleep(rand() % 3 + 1);
	}
	pthread_exit(NULL);
	pthread_cleanup_pop(0);
}

void *consume(void *arg)
{
	pthread_detach(pthread_self());
	pthread_cleanup_push(cleanup_handler, NULL);
	while (1) {
		pthread_mutex_lock(&mutex);
		while (isEmpty(&quene)) {
			pthread_cond_wait(&cond_pro, &mutex);
		}
		quene.front = (quene.front + 1) % N;
		printf("consume: %d\n", queneSize(&quene));
		pthread_mutex_unlock(&mutex);
		if (queneSize(&quene) == 19) {
			pthread_cond_broadcast(&cond_con);
		}
		sleep(rand() % 3 + 1);
	}
	pthread_exit(NULL);
	pthread_cleanup_pop(0);
}


int main(int argc, char *argv[])
{
	if (argc != 3) {
		perror("argument");
		exit(1);
	}
	int m = atoi(argv[1]);
	int n =	atoi(argv[2]);

	quene.front = 0;
	quene.rear = 0;
	pthread_cond_init(&cond_con, NULL);
	pthread_cond_init(&cond_pro, NULL);
	pthread_mutex_init(&mutex, NULL);
	srand(time(NULL));
	pthread_t *th = (pthread_t *)calloc(m + n, sizeof(pthread_t));
	int index = 0;
	for (index = 0; index < m; index++) {
		pthread_create(&th[index], NULL, produce, NULL);
	}
	sleep(2);
	for (; index < m + n; index++) {
		pthread_create(&th[index], NULL, consume, NULL);
	}
	while(1);
	pthread_cond_destroy(&cond_con);
	pthread_cond_destroy(&cond_pro);
	pthread_mutex_destroy(&mutex);
	return 0;
}
