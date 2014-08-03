/*
【程序 18】求 s=a+aa+aaa+aaaa+aa...a 的值
题目:求 s=a+aa+aaa+aaaa+aa...a 的值,其中 a 是一个数字。例如 2+22+222+2222+22222(此时 共有 5 个数相加),几个数相加有键盘控制。
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	int a, n;
	printf("Enter a and n: \n");
	scanf("%d%d", &a, &n);
	printf("a = %d, n = %d\n", a, n);
	int sum = 0; 
	int temp = 0;
	for (int i = 0; i < n; i++) {
		temp += a;
		sum += temp;
		a *= 10;
	}
	printf("a + aa + ... + aaaaa = %d", sum);	
	return 0;
}
