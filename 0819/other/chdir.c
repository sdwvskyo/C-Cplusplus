/*************************************************************************
	> File Name: chdir.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/19 09:53:07 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *buf;
	buf = getcwd(NULL, 0);
	printf("Current direct: %s", buf);
	return 0;
}
