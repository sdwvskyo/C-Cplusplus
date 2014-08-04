/*
实现一个9*9的乘法表
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d*%d = %-4d",i, j, i*j);
		}
		printf("\n");
	}

	return 0;
}
