/*
【程序 24】 求数列的前 20 项和,2/1,3/2,5/3,8/5,、 题目:有一分数序列:2/1,3/2,5/3,8/5,13/8,21/13...求出这个数列的前 20 项之和。
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	double f1 = 1;
	double f2 = 2;
	double sum = 0;
	double temp;
	for (int i = 0; i < 20; i++) {
		sum += f2 / f1;
		temp = f1 + f2;
		f1 = f2;
		f2 = temp;
		printf("sum = %f\n", sum);
	}

	return 0;
}
