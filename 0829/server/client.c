/*************************************************************************
	> File Name: client.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/29 21:31:03 2014
 ************************************************************************/

#include "chat.h"

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("argument is less\n");
		exit(1);
	}
	
	int sfd_client = initClient();
	struct sockaddr_in sever_addr;
	sever_addr.sin_family = AF_INET;
	sever_addr.sin_port = htons(atoi(argv[2]));
	sever_addr.sin_addr.s_addr = inet_addr(argv[1]);

	Buf buf;
	logIn(sfd_client, &sever_addr);
	if (fork() == 0) {
		char msg[N];
		while (memset(msg, 0, N), recvfrom(sfd_client, msg, N, 0, NULL, 0) != 0) {
			write(1, msg, strlen(msg));
		}
		close(sfd_client);
		exit(1);	
	}
	while (memset(&buf, 0, sizeof(buf)), fgets(buf.msg, N, stdin)) {
		buf.flag = 3;
		sendto(sfd_client, &buf, sizeof(buf), 0, 
				(struct sockaddr *)&sever_addr, sizeof(sever_addr));
	}	
	wait(NULL);
	logOff(sfd_client, &sever_addr);
	close(sfd_client);
	return 0;
}
