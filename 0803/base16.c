/*
16:第16题请编写一个函数float fun(double h),函数的功能使对变量h中的值保留2位小 树,并对第三位进行四舍五入(规定 h 中的值位正数)。
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	float num;
	while(scanf("%f", &num) == 1) {
		long tmp = (num * 1000 + 5) / 10;
		num = tmp / 100.0;
		printf("%.2f\n", num);
	}

	return 0;
}
