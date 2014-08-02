/*
100: 第 100 题 请编写函数 fun,其功能是:计算并输出 s=1+(1+2(0.5))+(1+2(0.5)+3(0.5))+... +(1+2(0.5)+3(0.5)+...+n(0.5))
*/

#include <stdio.h>

double fun1(int n) {
	if (1 == n)
		return 1.0;
	return n * 0.5 + fun1(n -1);
}

double fun2(int n) {
	int sum;
	for (int i = 2; i <= n; i++)
		sum += i;
	return 1.0 + sum * 0.5;
}


int main(void){
	int n;
	while (scanf("%d", &n) == 1) {
		printf("The result is : %.2f\n", fun2(n));
	}
	return 0;
}


