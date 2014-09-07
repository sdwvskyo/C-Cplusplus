/*************************************************************************
	> File Name: client.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  9/ 6 13:01:12 2014
 ************************************************************************/

#include "my_server.h"

int main(int argc, char *argv[])
{
	int sfd_client = initTcpClient(IP, PORT);
	printf("connect success!\n");
	char buf[N] = "";
	while (memset(buf, 0, N), fgets(buf, N, stdin)) {
		send(sfd_client, buf, strlen(buf), 0);
		memset(buf, 0, N);
		recv(sfd_client, buf, N, 0);
		write(1, buf, strlen(buf));
	}
	close(sfd_client);
	return 0;
}
