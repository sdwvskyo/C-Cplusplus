/*************************************************************************
	> File Name: client.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  8/28 23:05:40 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N 1024*1024
int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("argumen less!\n");
		exit(0);
	}
	char *ip = argv[1];
	short port = atoi(argv[2]);

	int fd_ftp = socket(AF_INET, SOCK_STREAM, 0);
	if (fd_ftp < 0) {
		perror("socket");
		exit(1);
	}

	struct sockaddr_in addr;
	int len = sizeof(addr);
	memset(&addr, 0, len);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(ip);
	addr.sin_port = htons(port);

	while (connect(fd_ftp, (struct sockaddr *)&addr, len) < 0) {
		printf("connecting\n");
		sleep(2);
	}
	printf("ftp connected!\n");
	char buf[N];
	char save_name[32];
	int cnt;
	cnt = 0;
	memset(save_name, 0, sizeof(save_name));
	printf("Enter download file name: ");
	scanf("%s", save_name);
	int fd_save = open(save_name, O_WRONLY | O_CREAT, 0666);
	if (fd_save < 0) {
		perror("open save file");
		exit(1);
	}
	while (memset(buf, 0, N), recv(fd_ftp, buf, N, 0) != 0) {
		write(fd_save, buf, strlen(buf));
		cnt++;
	}
	printf("Done! %d\n", cnt);
	close(fd_save);
	close(fd_ftp);
	return 0;
}
