/*************************************************************************
	> File Name: upper.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/19 21:26:22 2014
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int ch;
	while ((ch = getchar()) != EOF)
		putchar(toupper(ch));
	return 0;
}

