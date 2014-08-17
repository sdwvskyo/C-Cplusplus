/*************************************************************************
	> File Name: code9.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 13:58:09 2014
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[])
{
	int n;
	int i, j, k;
	while (scanf("%d", &n) == 1) {
		for (i = 1; i <= n; i++) {
			for (j = n - i; j >= 0; j--) {
				printf("  ");
			}
			for (k = 1; k <= i; k++) {
				printf("%2d", k);
			}
			k -= 2;
			for (; k >= 1; k--) {
				printf("%2d", k);
			}
			printf("\n");
		}
	}
	return 0;
}
