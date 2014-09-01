/*************************************************************************
	> File Name: sever.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  8/28 11:20:59 2014
 ************************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define N 1024

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("argument less");
		exit(1);
	}
	short port = atoi(argv[1]);
	int fd_server = socket(AF_INET, SOCK_STREAM, 0);
	if (fd_server < 0) {
		perror("fd_server");
		exit(1);
	}
	printf("socket make success!\n");

	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(port);

	if (bind(fd_server, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		perror("bind fd_server");
		close(fd_server);
		exit(1);
	}
	printf("socket bind success!\n");

	if (listen(fd_server, 10) < 0) {
		perror("listen success!\n");
		close(fd_server);
		exit(1);
	}
	printf("listen success!\n");
	
	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);
	memset(&client_addr, 0, client_addr_len);
	int fd_client1 = accept(fd_server, (struct sockaddr *)&client_addr, &client_addr_len);
	if (fd_client1 < 0) {
		perror("accept");
		close(fd_server);
		exit(1);
	}
	printf("client1 accept success!\n");
	printf("client1 address: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

	memset(&client_addr, 0, client_addr_len);
	int fd_client2 = accept(fd_server, (struct sockaddr *)&client_addr, &client_addr_len);
	if (fd_client2 < 0) {
		perror("accept");
		close(fd_server);
		exit(1);
	}
	printf("client2 accept success!\n");
	printf("client2 address: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

	char buf[1024];
	if (fork() == 0) {
		while (memset(buf, 0, N), recv(fd_client1, buf, N, 0) != 0) {
			send(fd_client2, buf, strlen(buf), 0);
		}
		close(fd_client1);
		close(fd_client2);
		close(fd_server);
		exit(1);
	}
	while (memset(buf, 0, N), recv(fd_client2, buf, N, 0) != 0) {
		send(fd_client1, buf, strlen(buf), 0);
	}
	close(fd_client1);
	close(fd_client2);
	close(fd_server);
	wait(NULL);
	return 0;
}
