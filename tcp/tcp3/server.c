#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "sysutil.h"
#include <fcntl.h>

#define ERR_EXIT(m) \
	do { \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

void do_service(int peerfd);

int main(int argc, const char *argv[])
{
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd == -1)
		ERR_EXIT("socket");

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (bind(listenfd, (struct sockaddr *)&addr, sizeof addr) == -1)
		ERR_EXIT("bind");
	if (listen(listenfd, SOMAXCONN) == -1)
		ERR_EXIT("listen");

	int peerfd = accept(listenfd, NULL, NULL);
	if (peerfd == -1)
		ERR_EXIT("accept");

	do_service(peerfd);
	
	close(listenfd);
	close(peerfd);
	return 0;
}

void do_service(int peerfd)
{
	int cnt = 0;
	char recvbuf[1024000] = {0};
	while(1) {
		memset(recvbuf, 0, sizeof recvbuf);

		int32_t len = recv_int32(peerfd);
		ssize_t nread = readn(peerfd, (void *)recvbuf, len);
		if (nread == -1)
			ERR_EXIT("readn");
		else if (nread == 0 || nread < len) {
			printf("client close...\n");
			exit(EXIT_FAILURE);
		}

		printf("count = %d, receive size = %ld\n", ++cnt, nread);
	}
}



