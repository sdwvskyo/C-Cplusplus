/*
【程序 10】题目:打印楼梯,同时在楼梯上方打印两个笑脸。
*/

#include <stdio.h>

int main(void) {
	printf("\1\1\n");
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j <= i; j++)
			printf("%c%c", 219, 219);
		printf("\n");
	}

	return 0;
}
