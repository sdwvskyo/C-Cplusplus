/*************************************************************************
	> File Name: code15.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 21:39:41 2014
 ************************************************************************/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int n;
	srand(time(0));
	while (scanf("%d", &n) == 1) {
		int ar[n];
		int i, j;
		for (i = 0; i < n; i++) {
			ar[i] = rand() % 100;
		}
		int cur = 0;
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++) {
				printf("%3d", ar[(cur++) % n]);
			}
			printf("\n");
			cur++;
		}
		printf("\n");
	}
	return 0;
}
