/*
将一个int型变量进行翻转
*/

#include <stdio.h>

int fanzhuan(int n);

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) == 1) {
		printf("fanzhuan hou = %d\n", fanzhuan(n));
	}
	return 0;
}

int fanzhuan(int n) {
	int tmp;
	int rst = 0;
	while (n) {
		tmp = n % 10;
		n /= 10;
		rst = rst * 10 + tmp;
	}
	return rst;
}

