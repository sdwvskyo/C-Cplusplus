/*************************************************************************
	> File Name: select_sort.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/15 15:51:50 2014
 ************************************************************************/
#include "func.h"

void select_sort(int *arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (min != i) {
			int tmp = arr[min];
			arr[min] = arr[i];
			arr[i] = tmp;
		}
	}
}

