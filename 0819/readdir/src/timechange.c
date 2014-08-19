/*************************************************************************
	> File Name: ./src/timechange.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/19 16:00:58 2014
 ************************************************************************/

#include "readdir.h"

void timeWithoutSec(time_t src_time, char *dst_time)
{
	char *tmp = ctime(&src_time);
	while (*tmp++ != ' ')
		;
	int high = strlen(tmp);
	while(tmp[high] != ':') {
		high--;
	}
	tmp[high] = '\0';
	strcpy(dst_time, tmp);
}

