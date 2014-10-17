#include "sysutil.h"

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
	#define SIZE 1024

	char sendbuf[SIZE + 1] = {0};
	int cnt = 0;

	while (1) {

		int i;
		for (i = 0; i < 10; ++i) {
			send_msg_with_len(sockfd, sendbuf, SIZE);

			printf("count = %d, writen = %d\n", ++cnt, SIZE);
		}
		nano_sleep(2.5);
	}
}

