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

#define 

typedef struct sockaddr Sa;
typedef struct sockaddr_in Si;

int my_socket(char *protoal, char *ip, int port);
int my_accept(int sfd, Si *client_addr, int *addr_len);
int my_send(int sfd, void *base, int len);
int my_recv(int sfd, void *base, int len);
int my_sendto(int sfd, void *base, int len, Si)


#endif
