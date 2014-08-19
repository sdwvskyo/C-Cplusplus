/*************************************************************************
	> File Name: useupper.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/19 21:28:38 2014
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		perror("argv");
		exit(1);
	}
	char *filename = argv[1];
	if (freopen(filename, "r", stdin) == NULL) {
		perror("reopen file");
		exit(2);
	}
	execl("./upper", "upper", 0);
	perror("execl ./a.out");
	exit(3);
}
