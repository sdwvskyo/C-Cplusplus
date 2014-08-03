/*
【程序 19】完数。 题目:一个数如果恰好等于它的因子之和,这个数就称为“完数”。例如 6=1+2+3.编程 找出 1000 以内的所有完数。
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	int ar[200];
	for (int i = 2; i <= 10000; i++) {
		int sum = 0;
		int k = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0)
				sum += j;
		}
		if (sum == i)
			printf("%d shi wanshu.\n", i);
	}

	return 0;
}


