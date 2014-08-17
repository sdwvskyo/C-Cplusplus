/*************************************************************************
	> File Name: code12.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 21:16:44 2014
 ************************************************************************/
//12.用 0-9 这十个数字可以组成多少无重复的 3 位数字

#include<stdio.h>

int main(int argc, char *argv[])
{
	int i, j, k;
	int cnt = 0;
	for (i = 1; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			for (k = 0; k < 10; k++) {
				if ((i != j) && (i != k) && (j != k)) {
					cnt++;
					printf("%d: %d%d%d\t", cnt, i, j, k);
					if (cnt % 4 == 0) {
						printf("\n");
					}
				}
			}
		}
	}
	printf("\n");
	return 0;
}
