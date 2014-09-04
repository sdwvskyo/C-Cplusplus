/*************************************************************************
	> File Name: /Users/sdw/sdw/wangdao/C/0904/topk/topk.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  9/ 4 20:29:29 2014
 ************************************************************************/

#include "topk.h"

static void swap(int *ar, int a, int b)
{
	int tmp;
	tmp = ar[a];
	ar[a] = ar[b];
	ar[b] = tmp;
}

static void heapAdjustSmall(int *ar, int i, int length)
{
	int key = ar[i];
	for (int j = i * 2 + 1; j < length; j = j * 2 + 1) {
		if (j < length - 1 && ar[j + 1] < ar[j]) {
			j++;
		}
		if (key <= ar[j]) {
			break;
		}
		ar[i] = ar[j];
		i = j;
	}
	ar[i] = key;
}

static void heapCreate(int *ar, int len)
{
	for (int i = len / 2 - 1; i >= 0; i--) {
		heapAdjustSmall(ar, i, len);
	}
}

void heapSort(int *ar, int len)
{
	heapCreate(ar, len);
	for (int i = len - 1; i > 0; i--) {
		swap(ar, 0, i);
		heapAdjustSmall(ar, 0, i);
	}
}

void topk_heap(int *ar, int len, int k)
{
	heapCreate(ar, k);
	for (int i = k; i < len; i++) {
		if (ar[i] > ar[0]) {
			swap(ar, 0, i);
			heapAdjustSmall(ar, 0, k);
		}
	}
}

int * initArr(int len) 
{
	int *ar = (int *)calloc(len, sizeof(int));
	for (int i = 0; i < len; i++) {
		ar[i] = rand() % 1000;
	}
	return ar;
}

void showArr(int *ar, int len)
{
	for (int i = 0; i < len; i++) {
		printf("%5d", ar[i]);
	}
	printf("\n");
}

static int partition(int *ar, int low, int high)
{
	int key = ar[low];
	while (low < high) {
		while (low < high && ar[high] >= key)
			high--;
		ar[low] = ar[high];
		while (low < high && ar[low] <= key)
			low++;
		ar[high] = ar[low];
	}
	ar[low] = key;
	return low;
}

void topk_quick(int *ar, int low, int high, int k)
{
	int mid;
	if (low < high) {
		mid = partition(ar, low, high);
		if (mid == k) {
			return;
		} else if (mid < k) {
			topk_quick(ar, mid + 1, high, k - mid);
		} else if (mid > k) {
			topk_quick(ar, low, mid - 1, k);
		}
	}
}
