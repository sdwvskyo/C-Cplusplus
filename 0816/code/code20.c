/*************************************************************************
	> File Name: code20.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  8/17 01:17:11 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1024

int match(char *s, char *t)
{
	int n = strlen(s) - 1;
	int m = strlen(t) - 1;
	int i = 0;
	int	j = 0;
	while (i <= n && j <= m) {
		if (s[i] == t[j]) {
			i++;
			j++;
		} else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j > m) {
		return i - m;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	char s[N];
	char t[N];

	while (fflush(stdin), scanf("%s%s", s, t)) {
		printf("%d\n", match(s, t));
	}
	return 0;
}
