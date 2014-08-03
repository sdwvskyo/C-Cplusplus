/*
【程序 30】一个 5 位数,判断它是不是回文数。
题目:一个 5 位数,判断它是不是回文数。即 12321 是回文数,个位与万位相同,十位与千位相同。
*/

#include <stdio.h>
#include <string.h>

int fun(char *str) {
	int len = (int)strlen(str);
	for (int i = 0; i < len / 2; i++, len--)
		if (str[i] != str[len - 1])
			return 0;
	return 1;
}
	
int main(int argc, char *argv[]) {
	char str[100];
	while (scanf("%s", str) == 1) {
		if(str == NULL || str[0] == '\0')
			break;
		if(strlen(str) == 1) {
			printf("is not huiwen.\n");
			continue;
		}
		if (fun(str))
			printf("is huiwen.\n");
		else 
			printf("is not huiwen.\n");
	}
	return 0;
}
