/*************************************************************************
	> File Name: system1.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  8/20 15:31:42 2014
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	if (argc < 2) {
		perror("argv");
		exit(1);
	}
	int a, b;
	char line[1024];
	int ret;
	while (printf(">>"), scanf("%d%d", &a, &b) == 2) {
		sprintf(line, "./%s %d %d", argv[1], a, b);
		ret = system(line);
		printf("%d\n", ret / 255);
		while (getchar() != '\n')
			continue;
		
	}
	return 0;
}
