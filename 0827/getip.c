/*************************************************************************
	> File Name: getip.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  8/28 14:26:04 2014
 ************************************************************************/

#include<stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("argument less\n");
		exit(1);
	}
	char *ptr;
	ptr = argv[1];
	struct hostent *phostent = gethostbyname(ptr);
	if (phostent == NULL) {
		perror("get hostent");
		exit(1);
	}
	printf("Official hostname: %s\n", phostent->h_name);

	char **pptr = phostent->h_aliases;
	while (*pptr) {
		printf("alias: %s\n", *pptr);
		pptr++;
	}
	printf("IP kind: %d\n", phostent->h_addrtype);
	printf("IP length: %d\n", phostent->h_length);
	pptr = phostent->h_addr_list;
	char buf[1024];
	while (*pptr) {
		printf("IP: %s\n", inet_ntop(phostent->h_addrtype, *pptr, buf, 1024));
		pptr++;
	}
	return 0;
}
