/*************************************************************************
	> File Name: client.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  8/28 15:41:43 2014
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N 1024

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("argument less");
		exit(1);
	}
	char *ip = argv[1];
	short port = atoi(argv[2]);
	int fd_server = socket(AF_INET, SOCK_STREAM, 0);
	if (fd_server < 0) {
		perror("fd_client");
		exit(1);
	}
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr(ip);
	server_address.sin_port = htons(port);

	if (connect(fd_server, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
		perror("connect");
		exit(1);
	}
	printf("connect success!\n");

	char buf[N];
	if (fork() == 0) {
		while (memset(buf, 0, N), recv(fd_server, buf, N, 0) != 0) {
			write(1, buf, strlen(buf));
		}
		close(fd_server);
		exit(1);
	}
	while (memset(buf, 0, N), fgets(buf, N, stdin) != NULL) {
		send(fd_server, buf, strlen(buf), 0);
	}
	
	close(fd_server);
	wait(NULL);
	printf("log off!\n");
	return 0;
}
