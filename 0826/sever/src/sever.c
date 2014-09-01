/*************************************************************************
	> File Name: sever.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/26 23:17:09 2014
 ************************************************************************/

#include "sever.h"

//Queue impletation
void initQueue(Queue *queue)
{
	memset(queue->task, 0, sizeof(Task) * TASK_MAX);
	queue->front = 0;
	queue->rear = 0;
}

int isFull(Queue *queue)
{
	return (queue->rear + 1) % TASK_MAX == queue->front;
}

int isEmpty(Queue *queue)
{
	return queue->rear == queue->front;
}

int queueLength(Queue *queue)
{
	return (queue->rear + TASK_MAX - queue->front) % TASK_MAX;
}

void enQueue(Queue *queue, Task *task)
{
	pthread_mutex_lock(&mutex);
	if (isFull(queue)) {
		pthread_cond_wait(&cond_master, &mutex);
	}
	queue->task[queue->rear] = *task;
	queue->rear = queue->rear % TASK_MAX;
	if (queueLength(queue) == (TASK_MAX - 2)) {
		pthread_cond_broadcast(&cond_slaver);
	}
	pthread_mutex_unlock(&mutex);
}

void deQueue(Queue *queue, Task *task)
{
	pthread_mutex_lock(&mutex);
	if (isEmpty(queue)) {
		pthread_cond_wait(&cond_slaver, &mutex);
	}
	*task = queue->task[queue->front];
	queue->front = (queue->front + 1) % TASK_MAX;
	pthread_mutex_unlock(&mutex);
}

//LinkList impletation
void initList(List **list)
{
	*list = NULL;
}

void addClient(List **list, int fd_recv, int fd_send)
{
	List *pNew = (List *) calloc(1, sizeof(List));
	if (pNew == NULL) {
		perror("calloc");
		exit(1);
	}
	pNew->fd_recv = fd_recv;
	pNew->fd_send = fd_send;
	pNew->next = *list;
	*list = pNew;
}

int deleteClient(List **list, int fd_recv)
{
	List *pCur = *list;
	List *pPre = NULL;
	while (pCur) {
		if (fd_recv == pCur->fd_recv) {
			break;
		}
		pPre = pCur;
		pCur = pCur->next;
	}
	if (pCur == NULL) {
		return -1;
	}
	if (pPre == NULL) {
		*list = pCur->next;	
	} else {
		pPre->next = pCur->next;
	}
	free(pCur);
	return 1;
}

int findClient(List *list, int fd_recv)
{
	while (list) {
		if (fd_recv == list->fd_recv) {
			break;
		}
		list = list->next;
	}
	return list != NULL ? 1 : 0;
}

void doTask(Task *task)
{
	write(task->fd_send, task->data, strlen(task->data));
}

void *thread_handler(void *arg)
{
	pthread_detach(pthread_self());
	Queue *queue = (Queue *)arg;
	Task task;
	deQueue(queue, &task);
	doTask(&task);
	pthread_exit(NULL);
}

void connectClient(char *buf, List **list)
{
	char tmp1[N];
	memset(tmp1, 0, N);
	sprintf(tmp1, "r.%s", buf);
	int fd_send = open(tmp1, O_WRONLY);
	if (fd_send < 0) {
		perror("open fd_send");
		exit(1);
	}

	char tmp2[N];
	memset(tmp2, 0, N);
	sprintf(tmp2, "w.%s", buf);
	int fd_recv = open(tmp2, O_RDONLY);
	if (fd_recv < 0) {
		perror("open fd_recv");
		exit(1);
	}
	addClient(list, fd_recv, fd_send);
	printf("%s on!\n", buf);
}

void traverseList(List **list, Queue *queue, fd_set *set, fd_set *back)
{
	List *pCur = *list;
	char buf[N];
	while (pCur) {
		if (FD_ISSET(pCur->fd_recv, set)) {
			memset(buf, 0, N);
			if (read(pCur->fd_recv, buf, N) == 0) {
				FD_SET(pCur->fd_recv, back);
				close(pCur->fd_recv);
				close(pCur->fd_send);
				deleteClient(list, pCur->fd_recv);
			} else {
				Task task;
				memset(&task, 0, sizeof(Task));
				strcpy(task.data, buf);
				task.fd_send = pCur->fd_send;
				enQueue(queue, &task);
				
			}
		}
		pCur = pCur->next;
	}
}

