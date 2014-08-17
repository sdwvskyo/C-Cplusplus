/*************************************************************************
	> File Name: code16.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 21:54:12 2014
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[])
{
	int n;
	while (scanf("%d", &n) == 1) {
		int ar[n][n];
		int row;
		int col;
		int cur = 1;
		int i, j;
		for (i = 1; i < n * 2; i++) {
			if (i % 2 == 1) {
				row = (i <= n ? 0 : i % n);
				col = (i <= n ? i - 1 : n - 1);
				j = (i <= n ? i : 2 * n - i);
				for (; j > 0; j--) {
					ar[row++][col--] = cur++;
				}
			} else {
				row = (i <= n ? i - 1 : n - 1);
				col = (i <= n ? 0 : i % n);
				j = (i <= n ? i : 2 * n -i);
				for (; j > 0; j--) {
					ar[row--][col++] = cur++;
				}
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%-3d", ar[i][j]);
			}
			printf("\n");
		}

	}
	return 0;
}
