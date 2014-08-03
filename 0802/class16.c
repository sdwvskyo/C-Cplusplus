/*
【程序 16】求最大公约数和最小公倍数。 题目:输入两个正整数 m 和 n,求其最大公约数和最小公倍数。
*/

#include <stdio.h>

//int beishu(int m, int n) {


int yueshu(int m, int n) {
	int min = m < n ? m : n;
	int i;
	for (i = min; i >= 1; i--)
		if (m % i == 0 && n % i == 0)
			break;
	return i;
}
int yueshu2(int m, int n) {
	if (m < n) {
		m = m ^ n;
		n = m ^ n;
		m = m ^ n;
	}
	int temp;
	while (n) {
		temp = m % n;
		m = n;
		n = temp;
	}
	return m;
}


int main(int argc, char *argv[]) {

	int a, b;
	while (scanf("%d%d", &a, &b) == 2) {
		printf("Max yueshu = %d\n", yueshu2(a, b));
		printf("Min beishu = %d\n", a * b / yueshu(a, b));
	}
	return 0;
}
