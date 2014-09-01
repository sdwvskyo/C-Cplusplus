/*************************************************************************
	> File Name: test.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  8/24 11:28:07 2014
 ************************************************************************/

#include<stdio.h>

int sum1(int n)
{
	int i;
	int sum = 0;
	for (i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int i;
	int sum = 0;
	for (i = 1; i <= 10; i++) {
		sum += i;
	}

	printf("result: %d\n", sum);
	printf("result: %d\n", sum1(10));

	return 0;
}
