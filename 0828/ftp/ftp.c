/*************************************************************************
	> File Name: ftp.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  8/28 23:52:59 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SIZE 1024 * 1024

int main(int argc, char *argv[]) 
{
	if (argc < 2) {
		printf("argument less");
		exit(1);
	}
	int fd_conf = open(argv[1], O_RDONLY);
	if (fd_conf < 0) {
		perror("open config file");
		exit(1);
	}
	FILE *fp_conf = fdopen(fd_conf, "r");
	if (fp_conf == NULL) {
		perror("open fp_conf");
		exit(1);
	}
	int  port;
	char ip[32];
	char filename[32];
	char line[128];
	memset(ip, 0, sizeof(ip));
	memset(filename, 0, sizeof(filename));
	memset(line, 0, sizeof(line));
	fgets(line, sizeof(line), fp_conf);
	sscanf(line, "%s", ip);
	memset(line, 0, sizeof(line));
	fgets(line, sizeof(line), fp_conf);
	sscanf(line, "%d", &port);
	memset(line, 0, sizeof(line));
	fgets(line, sizeof(line), fp_conf);
	sscanf(line, "%s", filename);
	fclose(fp_conf);
	close(fd_conf);

	int fd_ftp = socket(AF_INET, SOCK_STREAM, 0);
	if (fd_ftp < 0) {
		perror("ftp socket");
		exit(1);
	}
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	memset(&addr, 0, len);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(ip);
	addr.sin_port = htons(port);
	if (bind(fd_ftp, (struct sockaddr *)&addr, len) < 0) {
		perror("bind");
		exit(1);
	}
	if (listen(fd_ftp, 5) < 0) {
		perror("listen");
		exit(1);
	}
	char buf[SIZE];
	struct sockaddr_in client_addr;
	len = sizeof(client_addr);
	while (1) {
		memset(&client_addr, 0, len);
		int fd_client = accept(fd_ftp, (struct sockaddr *)&client_addr, &len);
		if (fd_client < 0) {
			perror("fd_client");
			exit(1);
		}
		int fd_file = open(filename, O_RDONLY);
		if (fd_file < 0) {
			perror("open file");
			exit(1);
		}
		if (fork() == 0) {
			close(fd_ftp);
			if (fork() == 0) {
				while (memset(buf, 0, SIZE), read(fd_file, buf, SIZE) != 0) {
					send(fd_client, buf, strlen(buf), 0);
				}
				close(fd_client);
				close(fd_file);
				exit(1);
			}
			close(fd_file);
			close(fd_client);
			exit(1);
		}
		wait(NULL);
		close(fd_client);
		close(fd_file);
	}
	close(fd_ftp);
	return 0;
}
