/*************************************************************************
	> File Name: merge_sort.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  9/ 7 20:07:31 2014
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *ar, int a, int b);
int * initArr(int len);
void showArr(int *ar, int len);
void merge(int *ar, int low, int mid, int high);
void merge_sort(int *ar, int low, int high);

int main(int argc, char *argv[])
{
	int len = atoi(argv[1]);
	int *ar = initArr(len);
	showArr(ar, len);
	merge_sort(ar, 0, len - 1);
	showArr(ar, len);
	return 0;
}

void merge(int *ar, int low, int mid, int high)
{
	int tmp[high+1];
	int i, j, k;
	for (i = 0; i <= high; i++)
		tmp[i] = ar[i];
	for (i = low, j = mid+1, k = i; i <= mid && j <= high; k++) {
		if (tmp[i] < tmp[j])
			ar[k] = tmp[i++];
		else 
			ar[k] = tmp[j++];
	}
	while (i <= mid)
		ar[k++] = tmp[i++];
	while (k <= high)
		ar[k++] = tmp[j++];
}

void merge_sort(int *ar, int low, int high)
{
	int mid;
	if (low < high) {
		mid = low + (high - low) / 2;
		merge_sort(ar, low, mid);
		merge_sort(ar, mid + 1, high);
		merge(ar, low, mid, high);
	}
}

void showArr(int *ar, int len)
{
	for (int i = 0; i < len; i++) {
		printf("%6d", ar[i]);
	}
	printf("\n");
}

int * initArr(int len)
{
	int *ar = (int *)calloc(len, sizeof(int));
	for (int i = 0; i < len; i++) {
		ar[i] = rand() % 10000;
	}
	return ar;
}
void swap(int *ar, int a, int b)
{
	int tmp;
	tmp = ar[a];
	ar[a] = ar[b];
	ar[b] = tmp;
}
