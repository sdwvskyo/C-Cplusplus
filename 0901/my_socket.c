#include "my_socket.h"

int initTcpServer(char *ip, int port)
{
	if (ip == NULL || port < 1024) {
		printf("Ip or port invalid!\n");
		exit(EXIT_FAILURE);
	}
	int sfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sfd < 0 ) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	Si addr;
	memset(&addr, 0, sizeof(Si));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);
	if (bind(sfd, (Sa *)&addr, sizeof(addr)) < 0) {
		perror("bind");
		close(sfd);
		exit(EXIT_FAILURE);
	}
	if (listen(sfd, 10) < 0) {
		perror("listen");
		close(sfd);
		exit(1);
	}
	return sfd;
}

int tcpAccept(int sfd)
{
	Si addr;
	socklen_t len = sizeof(Si);
	memset(&addr, 0, len);
	int new_sfd = accept(sfd, (Sa *)&addr, &len);
	if (new_sfd < 0) {
		perror("accept");
		close(sfd);
		exit(EXIT_FAILURE);
	}
	printf("%s:%d connect success!\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
	return new_sfd;
}

int initTcpClient(char *ip, int port)
{
	int sfd;
	Si addr;
	memset(&addr, 0, sizeof(Si));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);
	
	int cnt = 0;
	while (connect(sfd, (Sa *)&addr, sizeof(Si)) < 0) {
		sfd = socket(AF_INET, SOCK_STREAM, 0);
		if (sfd < 0) {
			perror("socket");
			exit(EXIT_FAILURE);
		}
		cnt++;
		if (cnt > CONNECT_TIMES) {
			printf("Connect time out!\n");
			close(sfd);
			exit(EXIT_FAILURE);
		}
		printf("connecting...\n");
		sleep(2);
	}
	return sfd;
}

int initUdpServer(char *ip, int port)
{
	int sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sfd < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	Si addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);
	if (bind(sfd, (Sa *)&addr, sizeof(Si)) < 0) {
		perror("bind");
		close(sfd);
		exit(EXIT_FAILURE);
	}
	return sfd;
}

int initUdpClient()
{
	int sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sfd < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	return sfd;
}

int sendTcp(int sfd, void *buf, int len)
{
	int sendn;
	int send_num = 0;
	while (send_num < len) {
		sendn = send(sfd, buf + send_num, len - send_num, 0);
		if (sendn < 0) {
			perror("send");
			exit(EXIT_FAILURE);
		}
		send_num += sendn;
	}
	return send_num;
}

int recvTcp(int sfd, void *buf, int len)
{
	int recvn;
	int recv_num = 0;
	while (recv_num < len) {
		recvn = recv(sfd, buf + recv_num, len - recv_num, 0);
		if (recvn < 0) {
			perror("recv");
			exit(EXIT_FAILURE);
		}
		recv_num += recvn;
	}
	return recv_num;
}

int sendTo(int sfd, const void *buf, int length, char *ip, int port)
{
	Si addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);
	int len = sendto(sfd, buf, length, 0, (Sa *)&addr, sizeof(Si));
	if (len == 0) {
		printf("0 byte send\n");
		exit(EXIT_FAILURE);
	}
	if (len < 0) {
		perror("sendto");
		exit(EXIT_FAILURE);
	}
	return len;
}

int recvFrom(int sfd, void *buf, int length, char *ip, int *port)
{
	Si addr;
	memset(&addr, 0, sizeof(Si));
	socklen_t addr_len = sizeof(Si);
	int len = recvfrom(sfd, buf, length, 0, (Sa *)&addr, &addr_len);
	if (len == 0) {
		printf("0 byte recv!\n");
		exit(EXIT_FAILURE);
	}
	if (len < 0) {
		perror("recvfrom");
		exit(EXIT_FAILURE);
	}
	if (ip != NULL) {
		strcpy(ip, inet_ntoa(addr.sin_addr));
	}
	if (port != NULL) {
		*port = ntohs(addr.sin_port);
	}
	return len;
}
