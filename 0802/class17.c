/*
【程序 17】输入一行字符,分别统计出其中英文字母、的个数。 题目:输入一行字符,分别统计出其中英文字母、空格、数字和其它字符的个数。
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	char ch;
	int letters = 0;
	int space = 0;
	int digits = 0;
	int others = 0;

	while ((ch = getchar()) != '\n') {
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			letters++;
		else if (ch >= '0' && ch <= '9')
			digits++;
		else if (ch == ' ')
			space++;
		else
			others++;
	}
	printf("letters = %d\ndigits = %d\nspace = %d\nothers = %d\n",
			letters, digits, space, others);

	return 0;
}
