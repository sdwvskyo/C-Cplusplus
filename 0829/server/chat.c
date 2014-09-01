/*************************************************************************
	> File Name: chat.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/29 20:09:52 2014
 ************************************************************************/

#include "chat.h"

int initServer(int port)
{
	int sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sfd < 0) {
		perror("socket");
		exit(1);
	}
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("bind");
		exit(1);
	}
	return sfd;
}

int initClient(void) 
{
	int sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sfd < 0) {
		perror("socket");
		exit(1);
	}
	return sfd;
}

void logIn(int sfd, struct sockaddr_in *addr) 
{
	Buf buf;
	memset(&buf, 0, sizeof(Buf));
	buf.flag = 0;
	if (sendto(sfd, &buf, sizeof(Buf), 0, (struct sockaddr *)addr, sizeof(*addr)) < 0) {
		perror("sendto server");
		exit(1);
	}
	printf("log in\n");
}

void logOff(int sfd, struct sockaddr_in *addr) 
{
	Buf buf;
	memset(&buf, 0, sizeof(Buf));
	buf.flag = 1;
	if (sendto(sfd, &buf, sizeof(Buf), 0, (struct sockaddr *)addr, sizeof(*addr)) < 0) {
		perror("sendto logoff");
		exit(1);
	}
	printf("log off!\n");
}

void addClient(Node **head, struct sockaddr_in *addr) 
{
	Node *pNew = (Node *)calloc(1, sizeof(Node));
	if (pNew == NULL) {
		perror("calloc");
		exit(1);
	}
	pNew->addr.sin_family = addr->sin_family;
	pNew->addr.sin_port = addr->sin_port;
	pNew->addr.sin_addr.s_addr = addr->sin_addr.s_addr;
	
	pNew->next = *head;
	*head = pNew;
}

void deleteClient(Node **head, struct sockaddr_in *addr)
{
	if (*head == NULL) {
		printf("list is empty");
		return;
	}
	Node *pCur = *head;
	Node *pPre = NULL;
	while (pCur) {
		if (pCur->addr.sin_addr.s_addr == addr->sin_addr.s_addr) {
			break;
		}
		pCur = pCur->next;
	}
	if (pPre == NULL) {
		*head = pCur->next;
	} else {
		pPre->next = pCur->next;
	}
	free(pCur);
}

void traverList(Node *head, int sfd, Buf *buf)
{
	while (head) {
		sendto(sfd, buf->msg, strlen(buf->msg), 0, (struct sockaddr *)&(head->addr),
				sizeof(head->addr));
		head = head->next;
	}
}

void initList(Node **head)
{
	*head = NULL;
}

