/*************************************************************************
	> File Name: thread3.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  8/21 09:55:53 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/semaphore.h>
void *thread_func(void *arg);

sem_t *bin_sem;

#define WORK_SIZE 1024
char work_area[WORK_SIZE];


int main(int argc, char *argv[])
{
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = sem_close(bin_sem);
	if (res != 0) {
		perror("sem destroy");
		exit(EXIT_FAILURE);
	}

	bin_sem = sem_open("sem1", O_CREAT, 0);  //竟然没有sem_int的实现。。。
	if (bin_sem == NULL) {
		perror("semaphore initialization failed.");
		exit(EXIT_FAILURE);
	}
	
	res = pthread_create(&a_thread, 0, thread_func, NULL);
	if (res != 0) {
		perror("thread create failed");
		exit(EXIT_FAILURE);
	}
	printf("Enter some string:\n");
	while (strncmp("end", work_area, 3) != 0) {
		fflush(stdin);
		fgets(work_area, WORK_SIZE, stdin);
		sem_post(bin_sem);
	}
	

	printf("\nWaiting for thread join...\n");
	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
		perror("thread joined failue");
		exit(EXIT_FAILURE);
	}
	printf("thread joined.\n");
	sem_close(bin_sem);
	sem_unlink("sem1");
	exit(EXIT_SUCCESS);
}

void *thread_func(void *arg)
{
	sem_wait(bin_sem);
	while (strncmp("end", work_area, 3) != 0) {
		printf("You have got %lu charactors.\n", strlen(work_area) - 1);
		sem_wait(bin_sem);
	}
	pthread_exit(NULL);
}
