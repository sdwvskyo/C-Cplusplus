/*
【程序 29】 不多于 5 位数,求是几位数。
题目:给一个不多于 5 位的正整数,要求:一、求它是几位数,二、逆序打印出各位数字。
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) == 1) {
		int a = n  / 10000;
		int b = n % 10000 / 1000;
		int c = n % 1000 / 100;
		int d = n % 100 / 10;
		int e = n % 10;
		if (a != 0)
			printf("There are 5: %d %d %d %d %d\n", e, d, c, b, a);
		else if (b != 0)
			printf("There are 4: %d %d %d %d\n", e, d, c, b);
		else if (c != 0)
			printf("There are 3: %d, %d, %d\n", e, d, c);
		else if (d != 0)
			printf ("There are 2: %d %d\n", e, d);
		else if (e != 0)
			printf("There is 1: %d\n", e);
		else {
			printf("Wrong number, enter again.\n");
			continue;
		}
			
	}
	return 0;
}
