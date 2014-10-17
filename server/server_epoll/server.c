//多线程服务器，收到请求则创建线程处理

#include "sysutil.h"
#include <signal.h>
#include <sys/epoll.h>
#define ERR_EXIT(m) \
	do { \
		perror(m);\
		exit(EXIT_FAILURE);\
	} while(0)


int main(int argc, char const *argv[])
{
	int listenfd = tcp_server("192.168.0.114", 8000);

	//创建epoll
	int epoll_fd = epoll_create(2048);
	if (epoll_fd == -1)
		ERR_EXIT("epoll_create");
	//初始化
	struct epoll_event ev;
	ev.data.fd = listenfd;
	ev.events = EPOLLIN;
	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listenfd, &ev) == -1)
		ERR_EXIT("epoll_ctl listenfd");

	//创建数组用于接收结果
	struct epoll_events events[2048];

	//epoll
	int nready = 0;
	while(1) {
		//wait
		nready = epoll_wait(epoll_fd, events, sizeof events, 2048);
		if (nready == -1) {
			if (errno == EINTR)
				continue;
			ERR_EXIT("epoll_wait");
		}
		else if (nready == 0) {
			printf("epoll timeout..\n");
			continue;
		}

		//遍历events数组 nready代表长度
		int i = 0;
		for (i = 0; i < nready; ++i) {
			int fd = events[i].data.fd;

			if (fd == listenfd) {
				if (events[i].events & EPOLLIN) {
					int peerfd = accept(fd, NULL, NULL);
					//加入epoll
					struct epoll_event ev;
					ev.data.fd = peerfd;
					ev.events = EPOLLIN;
					if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, peerfd, &ev) == -1)
						ERR_EXIT("epoll_ctl");
				}
			}
			else {	//普通fd
				if (events[i].events & EPOLLIN) {
					char recvbuf[1024] = {0};
					size_t nread = recv_msg_with_len(fd, recvbuf, sizeof recvbuf);
					if (nread == 0) {
						//从epoll中删除
						struct epoll_event ev;
						ev.data.fd = fd;
						if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, &ev) == -1)
							ERR_EXIT("epoll delete clinets");
						close(fd);
						continue;
					}
					printf("receive msg : %d\n", nread);
					send_msg_with_len(fd, recvbuf, nread);
				}
			}
		} 
	}

	close(listenfd);

	return 0;
}




