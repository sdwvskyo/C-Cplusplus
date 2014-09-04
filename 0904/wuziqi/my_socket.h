#ifndef _MY_SOCKET_H
#define _MY_SOCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define CONNECT_TIMES 10

typedef struct sockaddr Sa;
typedef struct sockaddr_in Si;

int initTcpServer(char *ip, int port);
int tcpAccept(int sfd);
int initTcpClient(char *ip, int port);
int initUdpServer(char *ip, int port);
int initUdpClient();
int sendTcp(int sfd, void *buf, int len);
int recvTcp(int sfd, void *buf, int len);
int sendTo(int sfd, const void *buf, int length, char *ip, int port);
int recvFrom(int sfd, void *buf, int length, char *ip, int *port);
#endif
