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
	Msg msg;
	while (memset(&msg, 0, sizeof(Msg)), fgets(msg.buf, MSG_SIZE, stdin) != NULL) {
		msg.len = strlen(msg.buf);
		sendTcp(sfd_client, &msg, msg.len + 4);
		memset(&msg, 0, sizeof(Msg));
		recvTcp(sfd_client, &msg, 4);
		recvTcp(sfd_client, msg.buf, msg.len);
		write(1, msg.buf, strlen(msg.buf));
	}
	memset(&msg, 0, sizeof(Msg));
	sendTcp(sfd_client, &msg, 4 + msg.len);
	close(sfd_client);
	return 0;
}
