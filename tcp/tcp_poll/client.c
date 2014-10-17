#include "sysutil.h"
#include <poll.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0);

void do_service(int sockfd);

int main(int argc, char const *argv[])
{
	int peerfd = tcp_client(0);
	connect_host(peerfd, "192.168.0.114", 8976);

	printf("%s connected\n", get_tcp_info(peerfd));

	do_service(peerfd);

	close(peerfd);

	return 0;
}

void do_service(int sockfd)
{
	char sendbuf[1024] = {0};
	char recvbuf[1024] = {0};

	while (1) {
		struct pollfd fds[2];
		fds[0].fd = sockfd;
		fds[0].events = POLLIN;
		fds[1].fd = STDIN_FILENO;
		fds[1].events = POLLIN;

		int nready = poll(fds, sizeof fds, 5000);
		if (nready == -1) {
			if (errno == EINTR)
				continue;
			ERR_EXIT("poll");
		}
		else if (nready == 0) {
			printf("close...\n");
			exit(EXIT_FAILURE);
		}

		if (fds[0].events & POLLIN)	{
			int nread = recv_msg_with_len(sockfd, recvbuf, sizeof recvbuf);
			if (nread == 0) {
				printf("close....\n");
				exit(EXIT_FAILURE);
			}
			printf("receive msg %s\n", recvbuf);
		}

		if (fds[1].events & POLLIN) {
			fgets(sendbuf, sizeof sendbuf, stdin);
			send_msg_with_len(sockfd, sendbuf, strlen(sendbuf));
		}

	}
}

