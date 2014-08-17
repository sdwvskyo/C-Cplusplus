/*************************************************************************
	> File Name: test.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/15 12:21:37 2014
 ************************************************************************/
#include <stdlib.h>
#include<stdio.h>
int main(void)
{
	int *p;
	p = (int *)malloc(sizeof(int));
	*p = 10;
	return 0;
}
