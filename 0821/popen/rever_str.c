/*************************************************************************
	> File Name: rever_str.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  8/21 20:25:08 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void reverse(char *str, int start, int end);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		perror("argument");
		exit(1);
	}
	char line[1024] = "";
	memset(line, 0, 1024);
	int i;
	for (i = 1; i < argc - 1; i++) {
		strcat(line, argv[i]);
		strcat(line, " ");
	}
	strcat(line, argv[i]);
	reverse(line, 0, strlen(line) - 1);
	int start = 0;
	int end = 0;
	int flag = 0;
	while (line[end] != '\0') {
		if (isblank(line[end])) {
			if (flag == 1) {
				flag = 0;
				reverse(line, start, end - 1);
			}
		} else {
			if (flag == 0) {
				flag = 1;
				start = end;
			}
		}
		end++;
	}
	reverse(line, start, end - 1);
	printf("%s\n", line);

	return 0;
}

void reverse(char *str, int start, int end) 
{	
	while (start < end) {
		char ch = str[start];
		str[start] = str[end];
		str[end] = ch;
		start++;
		end--;
	}
}
