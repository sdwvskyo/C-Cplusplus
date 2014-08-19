/*************************************************************************
	> File Name: get_user.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  8/18 09:14:19 2014
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

#define N 1024

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("No argv input.\n");
		exit(1);
	}
	FILE *fp = fopen(argv[1], "rb");
	if(fp == NULL) {
		perror("open file error\n");
		exit(1);
	}

	int index = 0;
	char line[N];
	while (fgets(line, N, fp) != NULL) {
		if (line[0] == '#') {
			continue;
		}
		for (index = 0; line[index] != ':'; index++) {
			putchar(line[index]);
		}
		putchar('\n');
	}

	return 0;
}
