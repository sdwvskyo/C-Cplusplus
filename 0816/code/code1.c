/*************************************************************************
	> File Name: code1.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  8/17 15:24:43 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>

#define N 1024
int str_str(char *src, char *dst);
void str_sub(char *src, char *dst, int index, int len);
int longest_dupstr(char *src, char *dst);

int main(int argc, char *argv[])
{
	char src[N];
	char dst[N];
	printf("input: \n");
	fgets(src, N, stdin);
	int times = longest_dupstr(src, dst);
	printf("longest_dupstr : %s\n times: %d\n", dst, times);
	
	return 0;
}

int longest_dupstr(char *src, char *dst)
{
	int cnt = 0;
	int index;
	int times;
	int pos;
	for (index = 0; index < strlen(src); index++) {
		for (pos = 0; pos <= index; pos++) {
			str_sub(src, dst, pos, strlen(src) - index);
			cnt = str_str(src, dst);
			if (cnt >= 2) {
				return cnt;
			}
		}
	}
	return 0;
}

void str_sub(char *src, char *dst, int index, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		dst[i] = src[index++];
	}
	dst[i] = '\0';
}

int str_str(char *src, char *dst)
{
	int cnt = 0;
	int index = 0;
	char tmp[N];
	for (index = 0; index < strlen(src) - strlen(dst); index++) {
		str_sub(src, tmp, index, strlen(dst));
		if (strcmp(tmp, dst) == 0) {
			cnt++;
		}
	}
	return cnt;
}
