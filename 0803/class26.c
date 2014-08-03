/*
【程序 26】 题目:利用递归方法求 5!。
*/

#include <stdio.h>

long fun(int n) {
	if (n == 1)
		return n;
	return n * fun(n - 1);
}


int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) == 1) {
		printf("%ld\n", fun(n));
	}

	return 0;
}
