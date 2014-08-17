/*************************************************************************
	> File Name: code4.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 20:13:15 2014
 ************************************************************************/
//4. 找出 1000 以内的完美数

#include<stdio.h>

int main(int argc, char *argv[])
{
	int i, j;
	for (i = 1; i <= 1000; i++) {
		int sum = 0;
		for (j = 1; j < i; j++) {
			if (i % j == 0) {
				sum += j;
			}
		}
		if (sum == i) {
			printf("%d\t", i);
		}
	}
	printf("\n");
	return 0;
}
