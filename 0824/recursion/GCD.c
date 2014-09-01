/*************************************************************************
	> File Name: GCD.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  8/24 22:16:47 2014
 ************************************************************************/

#include<stdio.h>

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else 
		return GCD(b, a % b);
}

int main(int argc, char *argv[])
{
	int a, b;
	while (scanf("%d%d", &a, &b) == 2) {
		printf("GCD: %d\n", GCD(a, b));
	}
	return 0;
}
