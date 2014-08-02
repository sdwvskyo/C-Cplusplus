/*
97: 第 97 题 请编写函数 fun,其功能是:计算并输出下列多项式值: s=1+1/(1+2)+1/(1+2+3)+..1/(1+2+3...+50)
*/
#include <stdio.h>

double fun1(int n) {
	double sum = 0.0;
	for (int i = 1; i <= n; i++) {
		int t = 0.0;
		for (int j = 1; j <= i; j++) 
			t += j;
		sum += 1.0 / t;
	}
	return sum;
}
//递归有点问题，不会弄了
double fun2(int n) {
	if (n == 1)
		return 1;
	double temp;
	return 1.0 / (n + fun2(n - 1)) + fun2(n - 1);
}

int main(void) {

	int n;
	while (scanf("%d", &n) == 1) {
		printf("The result of fun1 = %.2f\n", fun1(n));
		printf("The result of fun2 = %.2f\n", fun2(n));
	}
	return 0;
}

