/*************************************************************************
	> File Name: serv_client.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  8/28 19:52:11 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define N 1024
#define ACTIVE 1
#define PASSIVE 0
#define SERVER_PORT 6080

void * handler(void *arg)
{
	int sfd_in = *(int *)arg;
	char buf[N];
	while (memset(buf, 0, N), recv(sfd_in, buf, N, 0) != 0) {
		write(1, buf, strlen(buf));
	}
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	int flag = PASSIVE;
	int sfd_in;
	if (argc == 2) {
		flag = ACTIVE;
	} else if (argc > 2) {
		printf("too many argument\n");
		exit(1);
	}
	int sfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sfd < 0) {
		perror("open socket");
		exit(1);
	}

	struct sockaddr_in addr;
	socklen_t addr_len = sizeof(addr);
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(SERVER_PORT);
	
	if (flag == PASSIVE) {
		addr.sin_addr.s_addr = INADDR_ANY;
		if (bind(sfd, (struct sockaddr *)&addr, addr_len) < 0) {
			perror("bind");
			close(sfd);
			exit(1);
		}
		if (listen(sfd, 5) < 0) {
			perror("listen");
			exit(1);
		}
		struct sockaddr_in client_addr;
		sfd_in = accept(sfd, (struct sockaddr *)&client_addr, &addr_len);
		if (sfd_in < 0) {
			perror("accept");
			close(sfd);
			exit(1);
		}
		printf("%s:%d connect!\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
	} else {
		sfd_in = sfd;
		addr.sin_addr.s_addr = inet_addr(argv[1]);
		while (connect(sfd, (struct sockaddr *)&addr, addr_len) < 0) {
			printf("connecting.....\n");
			sleep(2);
		}
		printf("connect success!\n");
	}
	pthread_t thd;
	pthread_create(&thd, NULL, handler, (void *)&sfd_in);

	char buf[N];
	while (memset(buf, 0, N), fgets(buf, N, stdin) != NULL) {
		send(sfd_in, buf, strlen(buf), 0);
	}
	pthread_join(thd, NULL);
	close(sfd);
	close(sfd_in);
	return 0;
}
