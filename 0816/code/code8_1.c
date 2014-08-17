/*************************************************************************
	> File Name: code8.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 17:42:00 2014
 ************************************************************************/

#include<stdio.h>

int fun(int day)
{
	if (day == 1) {
		return 1;
	} else {
		return (fun(day - 1) + 1) * 2;
	}
}

int main(int argc, char *argv[])
{
	int n;
	while (scanf("%d", &n) == 1) {
		printf("peach: %d\n", fun(n));
	}
	return 0;
}
