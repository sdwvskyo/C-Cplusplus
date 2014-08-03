/*
【程序 36】题目:求 100 之内的素数
*/

#include <stdio.h>
#include <math.h>

int leap(int n) {
	int key = (int)sqrt(n + 1);
	for (int i = 0; i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

int main(int argc, char *argv[]) {
	for (int i = 1; i <= 100; i++) 
		if (leap(i))
			printf("%d is leap\n", i);

	return 0;
}
