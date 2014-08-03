/*
17: 第 17 题 请编写一个函数 fun(char *s),该函数的功能使把字符串中的内容拟置。
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {
	char str[100];
	while (gets(str) != NULL) {
		if (str[0] == '\0')
			break;
		int len = (int)strlen(str) - 1;
		for(int i = 0; i <= len / 2; i++, len--) {
			char tmp = str[i];
			str[i] = str[len];
			str[len] = tmp;
		}
		for(int i = 0; i < strlen(str); i++)
			putchar(str[i]);
		printf("\n");
	}
	return 0;
}
