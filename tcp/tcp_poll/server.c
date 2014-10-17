#include "sysutil.h"

void do_service(int sockfd);

int main(int argc, char const *argv[])
{
	int listenfd = tcp_server("192.168.0.114", 8976);

	int peerfd = accept(listenfd, NULL, NULL);

	printf("%s connected\n", get_tcp_info(peerfd));

	do_service(peerfd);

	close(listenfd);
	close(peerfd);

	return 0;
}

void do_service(int sockfd)
{
	int cnt = 0;
	char recvbuf[1024000] = {0};
	while(1) {
		memset(recvbuf, 0, sizeof recvbuf);

	    size_t nread = recv_msg_with_len(sockfd, recvbuf, sizeof recvbuf);
	    if (nread == 0) {
	    	printf("client close..\n");
	    	break;
	    }
	    printf("count = %d, receive = %ld\n", ++cnt, nread);
	    send_msg_with_len(sockfd, recvbuf, nread);
	} 
}

