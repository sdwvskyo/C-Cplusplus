/*************************************************************************
	> File Name: shell.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  8/21 16:27:21 2014
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define N 1024

void print_promot();

void create_args(char **args, char *line);

int rm_blank(char *line);

int main(int argc, char *argv[])
{
	char line[N];
	memset(line, 0, N);
	while (print_promot(), fgets(line, N, stdin) != NULL) {
		if (line[0] == '\n') {
			continue;
		}
		line[strlen(line) - 1] = '\0';
		char **args;
		create_args(args, line);
		int n = rm_blank(line);
		args = (char **)calloc(n + 1, sizeof(char *));
	}
	return 0;
}

void print_promot()
{
	printf(">");
}

void create_args(char **args, char *line) 
{

}

void str_ncpy(char *dst, char *src, int start, int end)
{
	int index = 0;
	while (start <= end) {
		dst[index++] = src[start++];
	}
	dst[index] = '\0';
}

int rm_blank(char *line) 
{
	int flag = 0;
	int cnt = 0;
	char *p = line;
	while (*p) {
		if (isblank(*p)) {
			if (flag == 1) {
				*line++ = ' ';
				flag = 0;
			}
		} else {
			*line++ = *p;
			if (flag == 0) {
				flag = 1;
				cnt++;
			}
		}
		p++;
	}
	*line = '\0';
	return cnt;
}
