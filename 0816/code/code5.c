/*************************************************************************
	> File Name: code5.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 13:49:27 2014
 ************************************************************************/
//5. 求自然数中各位数字之和

#include<stdio.h>

int main(int argc, char *argv[])
{
	int n;
	printf("Input a integer:");
	while (scanf("%d", &n) == 1) {
		int sum = 0;
		while (n) {
			sum += (n % 10);
			n /= 10;
		}
		printf("Sum = %d\n", sum);
	}
	return 0;
}
