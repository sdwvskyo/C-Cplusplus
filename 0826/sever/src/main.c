/*************************************************************************
	> File Name: src/main.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/26 19:58:30 2014
 ************************************************************************/

#include "sever.h"

pthread_mutex_t mutex;
pthread_cond_t cond_master;
pthread_cond_t cond_slaver;

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("argument less");
		exit(1);
	}
	//make and open fifo from argv[1]
	if (access("1.fifo", F_OK) == -1) {
		if (mkfifo(argv[1], 0666) != 0) {
			perror("mkfio");
			exit(1);
		}
	}
	int fd_sever = open(argv[1], O_RDONLY);
	if (fd_sever < 0) {
		perror("open fifo");
		exit(1);
	}
	printf("open sever fifo\n");

	List *client_list;
	initList(&client_list);
	Queue task_queue;
	initQueue(&task_queue);

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond_master, NULL);
	pthread_cond_init(&cond_slaver, NULL);

	//Create thread
	int index;
	int thread_num = atoi(argv[2]);
	pthread_t *th = (pthread_t *)calloc(thread_num, sizeof(pthread_t));
	for (index = 0; index < thread_num; index++) {
		pthread_create(th + index, NULL, thread_handler, (void *)&task_queue);
	}

	fd_set set, back;
	FD_ZERO(&back);
	FD_SET(fd_sever, &back);
	struct timeval tm;
	tm.tv_sec = 10;
	tm.tv_usec = 0;
	int res;
	char buf[N];
	while (1) {
		set = back;
		res = select(N, &set, NULL, NULL, &tm);
		if (res <= 0) {
			continue;
		}
		if (FD_ISSET(fd_sever, &set)) {
			memset(buf, 0, N);
			if (read(fd_sever, buf, N) != 0) {
				connectClient(buf, &client_list);
			} else {
				continue;
			}
		} 
		traverseList(&client_list, &task_queue, &set, &back);
	}
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond_master);
	pthread_cond_destroy(&cond_slaver);
	close(fd_sever);
	unlink(argv[1]);
	return 0;
}
