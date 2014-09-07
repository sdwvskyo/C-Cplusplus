/*************************************************************************
	> File Name: my_server.h
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  9/ 5 23:21:54 2014
 ************************************************************************/

#ifndef _MY_SERVER_H
#define _MY_SERVER_H

#include <my_socket.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>

#define IP "192.168.0.114"
#define PORT 8888

#define BUSY 1
#define IDLE 0

#define N 1024

typedef struct child {
	int state;
	pid_t pid;
	int sfd;
} Child;

Child * initChilds(int len);
void send_fd(int sfd, int fd_file);
int recv_fd(int sfd);
void assignTask(Child *childs, int childs_len, int sfd);
void travelChilds(Child *childs, int childs_len, fd_set *set);
void work(int sfd);

#endif
