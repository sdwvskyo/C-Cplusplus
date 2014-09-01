/*************************************************************************
	> File Name: chat.h
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/29 18:56:58 2014
 ************************************************************************/

#ifndef _CHAT_H_
#define _CHAT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define N 1024

typedef struct buf {
	int flag;
	char msg[N];
} Buf;

typedef struct list {
	struct sockaddr_in addr;
	struct list *next;
} Node, *List;

int initServer(int port);
int initClient(void);

void logIn(int sfd, struct sockaddr_in *addr);
void logOff(int sfd, struct sockaddr_in *addr);

void initList(Node **head);
void addClient(Node **head, struct sockaddr_in *addr);
void deleteClient(Node **head, struct sockaddr_in *addr);
void traverList(Node *head, int sfd, Buf *buf);

#endif
