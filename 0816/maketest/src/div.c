/*************************************************************************
	> File Name: src/div.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 17:11:09 2014
 ************************************************************************/

#include "func.h"

double div(double a, double b)
{
	if (b == 0) {
		printf("diver can not < 0");
		return -1;
	} else {
		return a / b;
	}
}

