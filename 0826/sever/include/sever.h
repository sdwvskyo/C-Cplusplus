#ifndef _SEVER_H_
#define _SEVER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define N 1024
#define TASK_MAX 21

extern pthread_mutex_t mutex;
extern pthread_cond_t cond_master;
extern pthread_cond_t cond_slaver;

//The queue of the thread task
typedef struct task {
	char data[N];
	int fd_send;
} Task;

typedef struct queue {
	Task task[TASK_MAX];
	int front;
	int rear;
} Queue;

//LinkList of client
typedef struct list {
	int fd_recv;
	int fd_send;
	struct list *next;
} List;

//LinkList interface
void initList(List **list);
void addClient(List **list, int fd_recv, int fd_send);
int deleteClient(List **list, int fd_recv);
int findClient(List *list, int fd_recv);
//Queue interface
void initQueue(Queue *queue);
int isFull(Queue *queue);
int isEmpty(Queue *queue);
int queueLength(Queue *queue);
void enQueue(Queue *queue, Task *task);
void deQueue(Queue *queue, Task *task);

void *thread_handler(void *arg);
void doTask(Task *task);
void connectClient(char *buf, List **list);
void traverseList(List **list, Queue *queue, fd_set *set, fd_set *back);

#endif
