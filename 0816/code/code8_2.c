/*************************************************************************
	> File Name: code8_2.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 20:38:32 2014
 ************************************************************************/
//8.求 a+aa+aaa+....的 和。

#include<stdio.h>

int main(int argc, char *argv[])
{
	int a, n;
	while (scanf("%d%d", &a, &n) == 2) {
		int sum = 0;
		int tmp = 0;
		int i, j;
		for (i = 1; i <= n; i++) {
			tmp *= 10;
			tmp += a;
			sum += tmp;
			printf("%dth result: %d\n", i, sum);
		}
		printf("\n");
	}

	return 0;
}

