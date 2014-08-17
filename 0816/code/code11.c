/*************************************************************************
	> File Name: code11.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 14:19:48 2014
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[]) 
{
	int a, b;
	for (a = 0; a < 10; a++) {
		for (b = 0; b < 10; b++) {
			if((a*10 + b) * (b*10 + a) == 1855) {
				printf("a = %d, b = %d\n", a, b);
			}
		}
	}
	return 0;
}
