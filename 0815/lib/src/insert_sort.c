/*************************************************************************
	> File Name: insert_sort.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/15 15:47:31 2014
 ************************************************************************/
#include "func.h"

void insert_sort(int *arr, int n)
{
	int i, j;
	int tmp;
	for (i = 1; i < n; i++) {
		tmp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > tmp) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = tmp;
	}
}
