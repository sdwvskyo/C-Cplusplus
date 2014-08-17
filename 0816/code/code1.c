/*************************************************************************
	> File Name: code1.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  8/17 15:24:43 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>

#define N 1024

int main(int argc, char *argv[])
{
	char src[N];
	char dst[N];
	printf("input: \n");
	scanf("%s", src);
	int times = longest_dupstr(src, dst);
	printf("longest_dupstr : \n times: %d", dst, times);
	
	return 0;
}

int longest_dupstr(char *src, char *dst)
{
	int cnt = 0;
	int index;
	int times;
	for (index = 0; index < strlen(src); index++) {
		for ()
		str_sub(src, dst, index, strlen(src) - index);
		cnt = str_str(str, dst);

		if (cnt >= 2) {
			return cnt;
		} else {
			cnt = 0
		}
	}
	return cnt;
}

void str_sub(char *src, char *dst, int index, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		dst[i] = src[index++];
	}
	dst[i] = '\0';
}


