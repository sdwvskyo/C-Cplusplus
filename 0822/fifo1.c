/*************************************************************************
	> File Name: fifo1.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/22 10:46:38 2014
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("lack argument\n");
	}
	int res = mkfifo(argv[1], 0777);
	if (res == 0) {
		printf("FIFO created!\n");
	}
	exit(EXIT_SUCCESS);
}
