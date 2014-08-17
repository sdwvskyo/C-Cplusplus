/*************************************************************************
	> File Name: code6.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 20:21:11 2014
 ************************************************************************/
//6. 一个球从100米高度自由落下,每次落地后反弹跳回原高度的一半在落下,求它在第10
//  次落地时,共经过多少米以及第十次反弹多高。

#include<stdio.h>

int main(int argc, char *argv[])
{
	double height = 100;
	double sum = 0;
	int i;
	for (i = 1; i <= 10; i++) {
		sum += height;
		height /= 2;
		sum += height;
		printf("di %d ci tanqi jingguo %lfm, fantan %lf mi gao.\n", i, sum, height);
	}

	return 0;
}

