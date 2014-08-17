/*************************************************************************
	> File Name: code7.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 20:30:37 2014
 ************************************************************************/
//计算2/1 - 3/2 + 5/3 - 8/5.....

#include<stdio.h>

int main(int argc, char *argv[])
{
	int i;
	double sum = 0;
	double f1 = 1;
	double f2 = 2;
	for (i = 1; i <= 10; i++) {
		if (i % 2 != 0) {
			sum += f2 / f1;
		} else {
			sum -= f2/ f1;
		}
		int tmp = f2;
		f2 += f1;
		f1 = tmp;
		printf("%dth result: %lf\n", i, sum);
	}
	return 0;
}

