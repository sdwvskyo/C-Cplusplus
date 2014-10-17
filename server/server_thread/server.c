//多线程服务器，收到请求则创建线程处理

#include "sysutil.h"
#include <signal.h>
#include <pthread.h>
#define ERR_EXIT(m) \
	do { \
		perror(m);\
		exit(EXIT_FAILURE);\
	} while(0)


void *thread_func(void *arg);
void do_service(int sockfd);

int main(int argc, char const *argv[])
{
	if (signal(SIGCHLD, SIG_IGN) == SIG_ERR)
		ERR_EXIT("signal child");

	int listenfd = tcp_server("192.168.0.114", 8000);

	while(1) {
	    int peerfd = accept(listenfd, NULL, NULL);
	    if (peerfd == -1)
	    	ERR_EXIT("accept");

	    int *pfd = (int *)malloc(sizeof(int));
	    *pfd = peerfd;
	    pthread_t tid;
	    if (pthread_create(&tid, NULL, thread_func, pfd)) {
	    	free(pfd);
	    }
	}

	close(listenfd);

	return 0;
}


void *thread_func(void *arg)
{
	int peerfd = *(int *)arg;
	free(arg);
	pthread_detach(pthread_self());
	
	do_service(peerfd);
}


void do_service(int sockfd)
{
	char recvbuf[1024] = {0};

    while(1)
    {
        size_t nread = recv_msg_with_len(sockfd, recvbuf, sizeof recvbuf);
        if(nread == 0)
        {
            printf("close ...\n");
            close(sockfd);
            //exit(EXIT_SUCCESS);
            pthread_exit(0);
            break;
        }
        printf("receive msg : %ld\n", nread);
        send_msg_with_len(sockfd, recvbuf, nread);
    }
}





