
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

	fp = popen(argv[1], "w");
	while (memset(buf, 0, N), fgets(buf, N, stdin) != NULL) {
		fprintf(fp, "%s", buf);
	}

	return 0;
}
