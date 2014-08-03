/*
【程序 14】将一个正整数分解质因数。
题目:将一个正整数分解质因数。例如:输入 90,打印出 90=2*3*3*5。
*/


#include <stdio.h>

int main(int argc, char *argv[]) {
	int num;
	while (scanf("%d", &num) == 1) {
		for(int i = 2; i <= num; i++) {
			while (i != num) {
				if (num % i == 0) {
					printf("%d*", i);
					num /= i;
				}
				else 
					break;
			}
		}
		printf("%d\n", num);
	}
	return 0;
}
