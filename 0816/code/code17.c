/*************************************************************************
	> File Name: code17.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 23:45:09 2014
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[])
{
	int n;
	while (scanf("%d", &n) == 1) {
		if (n % 2 == 0) {
			printf("jishu only! input again.\n");
			continue;
		}
		int ar[n][n];
		int cur = 1;
		int row = 0;
		int col = n / 2;
		while (cur <= n * n) {
			ar[row][col] = cur;
			if (cur % n == 0) {
				row = (row + 1) % n;
			} else {
				row = (n + row - 1) % n;
				col = (col + 1) % n;
			}
			cur++;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%-3d", ar[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
