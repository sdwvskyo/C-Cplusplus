#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "sysutil.h"
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void do_service(int sockfd);

int main(int argc, char const *argv[])
{
	int peerfd = socket(AF_INET, SOCK_STREAM, 0);
	if (peerfd == -1)
		ERR_EXIT("socket");

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (connect(peerfd, (struct sockaddr *)&addr, sizeof addr) == -1)
		ERR_EXIT("connect");

	do_service(peerfd);
	return 0;
}

void do_service(int sockfd)
{
	#define SIZE 1024
	char sendbuf[SIZE+1] = {0};
	int i;
	int cnt = 0;
	while (1) {
		memset(sendbuf, 'a', SIZE);

		for (i =0; i < 10; ++i) {
			send_int32(sockfd, SIZE);
			if (writen(sockfd, sendbuf, SIZE) != SIZE)
				ERR_EXIT("writen");

			printf("count = %d, send len = %d\n", ++cnt, SIZE);
		}

		nano_sleep(3.2);
	} 
}






