/*************************************************************************
	> File Name: test.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  9/10 16:49:51 2014
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[])
{
	int n;
	char buf[100];
	scanf("%s", buf);
	sscanf(buf, "%d", &n);
	printf("%d\n", n);
	return 0;
}
