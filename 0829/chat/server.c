/*************************************************************************
	> File Name: server.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/29 15:06:29 2014
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
	if (argc < 2) {
		printf("argument is less\n");
		exit(1);
	}
	int sfd_server = socket(AF_INET, SOCK_DGRAM, 0);
	if (sfd_server < 0) {
		perror("socket");
		exit(1);
	}
	int port = atoi(argv[1]);
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	memset(&addr, 0, len);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sfd_server, (struct sockaddr *)&addr, len) < 0) {
		perror("bind");
		exit(1);
	}
	char buf[N];
	memset(buf, 0, N);
	struct sockaddr_in client_addr;
	len = sizeof(client_addr);
	memset(&client_addr, 0, len);
	if (recvfrom(sfd_server, buf, N, 0, (struct sockaddr *)&client_addr, &len) == 0) {
		printf("recvfrom client error");
		exit(1);
	}	
	write(1, buf, strlen(buf));

	if (fork() == 0) {
		while (memset(buf, 0, N), fgets(buf, N, stdin) != NULL) {
			sendto(sfd_server, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, len);
		}
		close(sfd_server);
		exit(1);
	}
	while(memset(buf, 0, N), recvfrom(sfd_server, buf, N, 0, (struct sockaddr *)&client_addr, &len) != 0) {
		write(1, buf, strlen(buf));
	}
	close(sfd_server);
	wait(NULL);
	return 0;
}
