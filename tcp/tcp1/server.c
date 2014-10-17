#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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

	//地址复用
	int on = 1;
	if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1)
		ERR_EXIT("setsockopt");

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
	char recvbuf[1024] = {0};
	while (1) {
		memset(recvbuf, 0, sizeof recvbuf);
		int nread = read(peerfd, recvbuf, sizeof recvbuf);
		if (nread == -1) {
			if (errno == EINTR)
				continue;
			ERR_EXIT("read");
		}
		else if (nread == 0) {
			printf("close...\n");
			exit(EXIT_SUCCESS);
		}
		write(peerfd, recvbuf, strlen(recvbuf));
	}
}











