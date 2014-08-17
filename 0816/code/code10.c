/*************************************************************************
	> File Name: code10.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 20:49:07 2014
 ************************************************************************/
//字母金字塔

#include<stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char ch;
	int n;
	while (scanf("%c", &ch) == 1) {
		if (islower(ch)) {
			n = ch - 'a';
		} else {
			n = ch -'A';
		}
		int i, j;
		char tmp;
		for (i = 0; i <= n; i++) {
			for (j = n; j > i; j--) {
				printf(" ");
			}
			for (tmp = ch - n; tmp <= ch - n + i; tmp++) {
				printf("%c", tmp);
			}
			for (tmp -= 2; tmp >= ch - n; tmp--) {
				printf("%c", tmp);
			}
			printf("\n");
		}
		
	}
	return 0;
}

