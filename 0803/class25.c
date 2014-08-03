/*
程序 25】 题目:求 1+2!+3!+...+20!的和
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	long sum = 0;
	for (int i = 1; i <= 20; i++) {
		long temp = 1;
		for (int j = i; j > 0; j--) {
			temp *= j;
		}
		printf("temp = %ld\n", temp);
		sum += temp;
	}

	printf("sum = %ld.\n", sum);
	return 0;
}
