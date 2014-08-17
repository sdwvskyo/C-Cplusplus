/*************************************************************************
	> File Name: environ.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/15 21:56:12 2014
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[])
{
	extern char **environ;
	int i;
	for (i = 0; environ[i] != NULL; i++) {
		printf("%s\n", environ[i]);
	}
	return 0;
}

