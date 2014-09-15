/*************************************************************************
	> File Name: main.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  9/12 19:22:43 2014
 ************************************************************************/

#include "multi_thread.h"

int main(int argc, char *argv[])
{
	assert(argc == 3);
	Crew crew;
	int status;
	status = initCrew(&crew);
	if (status != 0) {
		printf("initCrew wrong!\n");
		exit(EXIT_FAILURE);
	}
	status = startCrew(&crew, argv[1], argv[2]);
	return 0;
}

