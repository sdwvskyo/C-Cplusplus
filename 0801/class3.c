/*
【程序 3】加 100 是完全平方数
题目:一个整数,它加上 100 后是一个完全平方数,再加上 168 又是一个完全平方数,请问该数是多少? 1.程序分析:在 10 万以内判断,先将该数加上 100 后再开方,再将该数加上 268 后再开方,如果开方后 的结果满足如下条件,即是结果。
*/

#include <stdio.h>
#include <math.h>

int main(void) {
	long x, y;

	for (long i = 1; i < 100000; i++) {
		x = sqrt(i + 100);
		y = sqrt(i + 268);
		if(x * x == i + 100 && y * y == i + 268)
			printf("\n%ld\n", i);	
	}

	return 0;
}
