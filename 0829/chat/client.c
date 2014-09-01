/*************************************************************************
	> File Name: client.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/29 15:48:45 2014
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N 1024

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("argument is less\n");
		exit(1);
	}
	int sfd_client = socket(AF_INET, SOCK_DGRAM, 0);
	if (sfd_client < 0) {
		perror("socket");
		exit(1);
	}
	char *ip = argv[1];
	int port = atoi(argv[2]);
	struct sockaddr_in server_addr;
	socklen_t len = sizeof(server_addr);
	memset(&server_addr, 0, len);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = inet_addr(ip);

	char buf[N];
	memset(buf, 0, N);
	struct sockaddr_in client_addr;
	len = sizeof(client_addr);
	memset(&client_addr, 0, len);

	printf("connect!\n");
	if (fork() == 0) {
		while (memset(buf, 0, N), fgets(buf, N, stdin) != NULL) {
			sendto(sfd_client, buf, strlen(buf), 0, (struct sockaddr *)&server_addr, len);
		}
		close(sfd_client);
		exit(1);
	}
	while(memset(buf, 0, N), recvfrom(sfd_client, buf, N, 0, (struct sockaddr *)&server_addr, &len) != 0) {
		write(1, buf, strlen(buf));
	}
	close(sfd_client);
	wait(NULL);
	return 0;
}
