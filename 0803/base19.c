/*
19: 第 19 题 编写函数 fun,该函数的功能是:从字符中删除指定的字符,同一字母的大、小 写按不同字符处理。
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	char str[100];
	while (gets(str)) {
		if (str == NULL || str[0] == '\0')
			break;
		printf("Enter which charactor to delete: \n");
		char ch;
		scanf("%c", &ch);
		char *tmp = str;
		int i = 0;
		while(*tmp) {
			if(ch != *tmp)
				str[i++] = *tmp;
			tmp++;
		}
		str[i] = '\0';
		puts(str);
	}

	return 0;
}
