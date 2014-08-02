/*
【程序 8】题目:输出 9*9 口诀。
*/

#include <stdio.h>

int main(void) 
{
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j <= i; j++)
			printf("%d*%d=%2d\t", i, j, i * j);
		printf("\n");
	}
	return 0;
}

