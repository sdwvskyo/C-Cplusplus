/*************************************************************************
	> File Name: popen.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  8/21 22:34:44 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1024

int main(int argc, char *argv[])
{
	if (argc < 2) {
		perror("argv");
		exit(1);
	}
	FILE *fp;
	char buf[N];
	char cmd[N];
	while (memset(buf, 0, N), fgets(buf, N, stdin) != NULL) {
		memset(cmd, 0, N);
		buf[strlen(buf) - 1] = '\0';
		strcat(cmd, argv[1]);
		strcat(cmd, " ");
		strcat(cmd, buf);
		fp = popen(cmd, "r");
		fgets(buf, N, fp);
		printf("popen: %s", buf);
	}

	pclose(fp);
	return 0;
}
