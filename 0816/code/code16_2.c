/*************************************************************************
	> File Name: cede16_2.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  8/17 15:59:18 2014
 ************************************************************************/

#include<stdio.h>
#define IN(a, b, n) ((a >= 0) && (a < n) && (b >= 0) && (b < n))

int main(int argc, char *argv[])
{
	int n;
	while (scanf("%d", &n) == 1) {
		int ar[n][n];
		int i, j;
		int row;
		int cur = 1;
		for (i = 0; i < 2 * n - 1; i++) {
			if (i % 2 == 0) {
				for (row = 0; row <= i; row++) {
					if (IN(row, i - row, n)) {
						ar[row][i -row] = cur++;
					}
				}
			} else {
				for (row = i; row >= 0; row--) {
					if (IN(row, i - row, n)) {
						ar[row][i - row] = cur++;
					}
				}
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%3d", ar[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
