/*************************************************************************
	> File Name: popen_test.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/22 08:37:44 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define N 1024

int main(int argc, char *argv[])
{
	char buf[N + 1];
	memset(buf, 0, N);
	FILE *fp;
	fp = popen("uname -a", "r");
	if (fp == NULL) {
		perror("popen");
		exit(EXIT_FAILURE);
	}
	fgets(buf, N, fp);
	printf("%s\n", buf);
	pclose(fp);
	return 0;
}
