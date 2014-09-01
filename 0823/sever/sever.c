/************************************************************************
	> File Name: sever.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/23 18:54:58 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <fcntl.h>
#include <stdlib.h>

#define N 1024

typedef struct user {
	int id;
	int fd;
	int flag;
} User;

void send_msg(char *buf, User *users);
void conect_fifo(char *buf, User *users);
void close_fifo(char *buf, User *users);
int isEmpty(User *users);

int main(int argc, char *argv[])
{
	if (access(argv[1], F_OK) == -1) {
		if (mkfifo(argv[1], 0666) < 0) {
			perror("mkfifo");
			exit(1);
		}
	}
	User users[N];
	memset(users, 0, sizeof(User) * N);
	int fd_sever = open(argv[1], O_RDONLY);
	if (fd_sever < 0) {
		perror("open sever fifo");
		exit(1); 
	}

	fd_set back, set;
	FD_ZERO(&back);
	FD_SET(fd_sever, &back);
	struct timeval tm;
	tm.tv_sec = 5;
	tm.tv_usec = 0;

	char buf[N] = "";
	while (1) {
		set = back;
		select(fd_sever + 1, &set, NULL, NULL, &tm);
		if (FD_ISSET(fd_sever, &set)) {
			memset(buf, 0, N);
			if (read(fd_sever, buf, N) > 0) {
				if (strncmp(buf, "on", 2) == 0) {
					conect_fifo(buf, users);
				} else if (strncmp(buf, "off", 3) == 0) {
					close_fifo(buf, users);
				} else {
					send_msg(buf, users);
				}
			} else {
				printf("read nothing\n");
				continue;
			}
		} else {
			if (isEmpty(users)) {
				printf("All log off.\nBye!\n");
				break;
			}
			continue;
		}
		
	}
	close(fd_sever);
	unlink(argv[1]);
	return 0;
}

int isEmpty(User *users) 
{
	int index = 0;
	for (index = 0; index < N; index++) {
		if (users[index].flag == 1) {
			break;
		}
	}
	if (index == N) {
		return 1;
	}
	return 0;
}

void send_msg(char *buf, User *users)
{
	int res;
	int index = 0;
	for (index = 0; index < N; index++) {
		if (users[index].flag == 1) {
			res = write(users[index].fd, buf, strlen(buf));
			if (res < 0) {
				perror("write");
				exit(1);
			}
		}
	}
}

void conect_fifo(char *buf, User *users)
{
	int pid;
	int index = 0;
	sscanf(buf + 3, "%d", &pid);
	sprintf(buf, "%d.fifo", pid);
	for (index = 0; index < N; index++) {
		if (users[index].flag == 0) {
			break;
		}
	}
	users[index].id = pid;
	users[index].fd = open(buf, O_WRONLY);
	if (users[index].fd < 0) {
		perror("open fifo");
		exit(1);
	}
	users[index].flag = 1;
	printf("%d on\n", users[index].id);
}

void close_fifo(char *buf, User *users)
{
	int pid = 0;
	int index = 0;
	sscanf(buf + 4, "%d", &pid);
	for (index =0; index < N; index++) {
		if (users[index].id == pid) {
			break;
		}
	}
	close(users[index].fd);
	users[index].flag = 0;
	printf("%d off\n", users[index].id);
}






