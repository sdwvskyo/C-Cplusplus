/*************************************************************************
	> File Name: main.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/29 20:09:29 2014
 ************************************************************************/

#include "chat.h"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("argument less\n");
		exit(1);
	}
	int sfd_server = initServer(atoi(argv[1]));

	fd_set set, back;
	FD_ZERO(&back);
	FD_SET(sfd_server, &back);
	struct timeval tm;
	tm.tv_sec = 5;
	tm.tv_usec = 0;

	Buf buf;
	struct sockaddr_in client_addr;
	socklen_t len;
	List client_list;
	initList(&client_list);
	while (1) {
		set = back;
		len = sizeof(client_addr);
		memset(&client_addr, 0, len);
		select(sfd_server + 1, &set, NULL, NULL, &tm);
		if (FD_ISSET(sfd_server, &set)) {
			if (memset(&buf, 0, sizeof(Buf)), recvfrom(sfd_server, &buf, sizeof(Buf), 0, 
						(struct sockaddr *)&client_addr, &len) != 0) {
				if (buf.flag == 0) {
					addClient(&client_list, &client_addr);
					printf("%s:%d log in!\n", inet_ntoa(client_addr.sin_addr),
							htons(client_addr.sin_port));
				} else if (buf.flag == 1){
					deleteClient(&client_list, &client_addr);
					printf("%s:%d log off!\n", inet_ntoa(client_addr.sin_addr), 
							htons(client_addr.sin_port));
				} else {
					if (fork() == 0) {
						if (fork() == 0) {
							traverList(client_list, sfd_server, &buf);
							close(sfd_server);
							exit(1);
						}
						close(sfd_server);
						exit(1);
					}
					wait(NULL);
				}
			}
		} else {
			continue;
		}
	}
	close(sfd_server);
	return 0;
}
