/*
【程序 38】题目:求一个 3*3 矩阵对角线元素之和
*/

#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#define N 5

int main(int argc, char *argv[]) {
	int ar[N][N];
	srand(time(0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) { 
			ar[i][j] = rand() % 100;
			printf("%d\t", ar[i][j]);
		}
		printf("\n");
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += ar[i][i];

	printf("%d", sum);

	return 0;

}
