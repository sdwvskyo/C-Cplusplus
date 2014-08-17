/*************************************************************************
	> File Name: bubble_sort.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/15 15:44:50 2014
 ************************************************************************/

#include "func.h"

void bubble_sort(int *arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j+1]) {
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}
