/*************************************************************************
	> File Name: code2.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 18:49:42 2014
 ************************************************************************/
//2. 判断一个整数是不是回文数

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
int main(int argc, char *argv[])
{
	char str[N];
	while (memset(str, 0, N), scanf("%s", str) == 1) {
		int start = 0;
		int end = strlen(str) - 1;
		while (start++ < end--) {
			if (str[start] != str[end]) {
				break;
			}
		}
		if (start >= end) {
			printf("%s is huiwen.\n", str);
		} else {
			printf("%s is not huiwen.\n", str);
		}
	}
	return 0;
}
