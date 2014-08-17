/*************************************************************************
	> File Name: code13.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 14:24:53 2014
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[])
{
	int a, b;
	for (int i = 1000; i < 9999; i++) {
		a = i / 100;
		b = i % 100;
		if ((a + b) * (a + b) == i) {
			printf("%d\t", i);
		}
	}
	printf("\n");
	return 0;
}
