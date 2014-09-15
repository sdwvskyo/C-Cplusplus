/*************************************************************************
	> File Name: test.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  9/ 5 21:53:42 2014
 ************************************************************************/

#include "my_server.h"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("argumment less\n");
		exit(EXIT_FAILURE);
	}
	
	int childs_len = atoi(argv[1]);
	Child *childs = initChilds(childs_len);

	int sfd_server = initTcpServer(IP, PORT);
	fd_set set, back;
	FD_ZERO(&set);
	FD_ZERO(&back);
	FD_SET(sfd_server, &back);
	for (int i = 0; i < childs_len; i++) {
		FD_SET(childs[i].sfd, &back);
	}
	struct timeval tm;
	tm.tv_sec = 0;
	tm.tv_usec = 1000;
	int res = 0;
	int sfd_client;
	while (1) {
		set = back;
		res = select(N, &set, NULL, NULL, &tm);
		if (res == 0) {
			continue;
		} 
		if (res == -1) {
			if (errno == EINTR) {
				continue;
			} else {
				perror("select");
				exit(EXIT_FAILURE);
			}
		}
		if (FD_ISSET(sfd_server, &set)) {
			sfd_client = accept(sfd_server, NULL, NULL);
			assignTask(childs, childs_len, sfd_client);
			close(sfd_client);
		}
		travelChilds(childs, childs_len, &set);
	}
	close(sfd_server);
	return 0;
}
