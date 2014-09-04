/*************************************************************************
	> File Name: main.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  9/ 1 16:19:44 2014
 ************************************************************************/

#include "my_socket.h"

#define N 1024

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("argument less!\n");
		exit(1);
	}
	int sfd_server = initTcpServer(argv[1], atoi(argv[2]));
	int sfd_client = tcpAccept(sfd_server);
	char buf[N];
	if (fork() == 0) {
		while (memset(buf, 0, N), recv(sfd_client, buf, N, 0) != 0) {
			write(1, buf, strlen(buf));
		}
		close(sfd_client);
		close(sfd_server);
		exit(1);
	}
	while (memset(buf, 0, N), fgets(buf, N, stdin)) {
		send(sfd_client, buf, strlen(buf), 0);
	}
	wait(NULL);
	close(sfd_server);
	close(sfd_client);
	return 0;
}
