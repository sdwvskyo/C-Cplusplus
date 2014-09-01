/*************************************************************************
	> File Name: thread1.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  8/25 14:53:27 2014
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int i = 0;

pthread_mutex_t mutex;

void *handle(void *arg)
{
	for (int index = 0; index < 10000; index++) {
		pthread_mutex_lock(&mutex);
		i++;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main(void)
{
	pthread_t thd1;
	pthread_t thd2;
	pthread_mutex_init(&mutex, NULL);
	char *p = "hello world";
	pthread_create(&thd1, NULL, handle, (void *)p);
	pthread_create(&thd2, NULL, handle, (void *)p);
	int ret;
	pthread_join(thd1, (void *)&ret);
	pthread_join(thd2, (void *)&ret);
	printf("result = %d\n", i);
	return 0;
}
