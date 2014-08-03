/*
程序 12】判断 1010 到 200 之间的素数。
题目:判断 101-200 之间有多少个素数,并输出所有素数。
*/

#include <stdio.h>
#include <math.h>

int leap(int n) {
	int temp = sqrt(n + 1);
	for (int i = 2; i <= temp; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
	

int main(void) {
	for (int i = 100; i <= 200; i++)
		if (leap(i))
			printf("%d\t", i);
	return 0;
}

