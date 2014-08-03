/*
【程序 11】(古典问题)兔子问题。
题目:古典问题:有一对兔子,从出生后第 3 个月起每个月都生一对兔子,小兔子长到第三个月 后每个月又生一对兔子,假如兔子都不死,问每个月的兔子总数为多少?
*/

#include <stdio.h>

void fib1(int n);
int fib2(int n);

int main(void) {
	int n;
	while (scanf("%d", &n) == 1) {
		fib1(n);
		fib2(n);
	}
	return 0;
}

void fib1(int n) {
	long f1 = 1;
	long f2 = 1;
	for (int i = 1; i <= n; i++) {
		printf("%ld\t%ld\t", f1, f2);
		f1 = f1 + f2;
		f2 = f1 + f2;
	}
}

int fib2(int n) {
	if(1 == n || 2 == n)
		return 1;
	else {
		int rst = fib2(n - 1) + fib2(n - 2);
		return rst;
	}
}


