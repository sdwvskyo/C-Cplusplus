/*************************************************************************
	> File Name: rever.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/22 08:08:42 2014
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[])
{
	int i;
	for (i = argc - 1; i > 0; i--) {
		printf("%s", argv[i]);
	}
	char buf[100];
	scanf("%s", buf);
	printf("%s", buf);
	return 0;
}
