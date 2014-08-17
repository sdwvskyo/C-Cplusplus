/*************************************************************************
	> File Name: main.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/15 15:04:38 2014
 ************************************************************************/

#include "func.h"

void creat(int *ar, int n)
{
	int i;
	for(i = 0; i < n; i++) {
		ar[i] = rand() % 100;
	}
}

void print(int *ar, int n)
{
	int i;
	for(i = 0; i < n; i++) {
		printf("%d\t", ar[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	srand(time(NULL));
	int ar[n];
	creat(ar, n);
	print(ar, n);

	bubble_sort(ar, n);
	print(ar, n);
	
	return 0;
}

