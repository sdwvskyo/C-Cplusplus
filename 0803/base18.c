/*
18: 第 18 题 编写程序,实现矩阵(3 行 3 列)的转置(即行列互换)。
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int main(int argc, char * argv[]) {
	srand(time(0));
	int array[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			array[i][j] = rand() % 1000;
			printf("%4d",  array[i][j]);
		}
		printf("\n");
	}
	
	for(int i = 0; i < N; i++)
		for(int j = i; j < N; j++) {
			int tmp = array[i][j];
			array[i][j] = array[j][i];
			array[j][i] = tmp;
		}

	printf("\n\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%4d", array[i][j]);
		printf("\n");
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++) {
			int tmp = array[i][j];
			array[i][j] = array[j][i];
			array[j][i] = tmp;
		}

	printf("\n\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%4d", array[i][j]);
		printf("\n");
	}
	return 0;
}
