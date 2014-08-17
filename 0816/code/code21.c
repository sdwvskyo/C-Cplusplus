/*************************************************************************
	> File Name: code21.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 14:29:29 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#define N 1024

int main(int argc, char *argv[])
{
	char ar[N];
	while (fgets(ar, N, stdin) != NULL) {
		if (*ar == '\n') {
			break;
		}
		char *str = ar;
		int max = 0;
		int cnt = 0;
		while (*str) {
			if ((*str == ' ') || (*str == '\n') || (*str == '\t')) {
				if (max < cnt) {
					max = cnt;
				}
				cnt = 0;
			} else {
				cnt++;
			}
			str++;
		}
		printf("max size is: %d\n", max);
	}
}
