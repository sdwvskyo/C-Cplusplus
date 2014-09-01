/*************************************************************************
	> File Name: exp.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  8/24 22:57:54 2014
 ************************************************************************/

#include<stdio.h>

int Raise(int base, int exp)
{
	if (exp == 0) {
		return 1;
	}
	else {
		int half = Raise(base, exp / 2);
		if (exp % 2 == 0) {
			return half * half;
		}
		else {
			return base * half * half;
		}
	}
}

int main(void)
{
	int m, n;
	while (scanf("%d%d", &m, &n) == 2) {
		printf("exp: %d\n", Raise(m, n));
	}
	return 0;
}
