/*
程序 27】利用递归函数调用方式,反向打印字符。 题目:利用递归函数调用方式,将所输入的 5 个字符,以相反顺序打印出来。
*/

#include <stdio.h>

void palin(char *str) {
	if(*str != '\0')
		palin(str + 1);
	printf("%c", *str);
}


int main(int argc, char *argv[]) {
	char str[100];
	scanf("%s", str);
	palin(str);
	return 0;
}
