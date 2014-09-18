/*************************************************************************
	> File Name: quick_sort.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  9/ 2 14:52:58 2014
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int * initArr(int len);
void printArr(int *ar, int len);
void swap(int *ar, int a, int b);
void quick_sort(int *ar, int low, int high);
int partition1(int *ar, int low, int high);
int partition2(int *ar, int low, int high);
int partition3(int *ar, int low, int high);

int main(int argc, char *argv[2])
{
	if (argc < 2) {
		printf("argument is less\n");
		exit(EXIT_FAILURE);
	}
	srand(getpid());
	int len = atoi(argv[1]);
	int *ar = initArr(len);
	printArr(ar, len);
	quick_sort(ar, 0, len - 1);
	printArr(ar, len);
	return 0;
}

int * initArr(int len)
{
	int *ar = (int *)calloc(len, sizeof(int));
	if (ar == NULL) {
		perror("calloc");
		exit(1);
	}
	memset(ar, 0, sizeof(int) * len);
	for (int i = 0; i < len; i++) {
		ar[i] = rand() % 10000;
	}
	return ar;
}

void printArr(int *ar, int len)
{
	int cnt = 0;
	for (int i = 0; i < len; i++, cnt++) {
		printf("%6d", ar[i]);
	}
	printf("\n");
}

void quick_sort(int *ar, int low, int high)
{
	if (low < high) {
		int mid = partition3(ar, low, high);
		quick_sort(ar, low, mid - 1);
		quick_sort(ar, mid + 1, high);
	}
}

int partition1(int *ar, int low, int high)
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

int partition2(int *ar, int low, int high)
{
	int key = ar[low];
	low--;
	high++;
	while (1) {

		do high--;
		while (ar[high] > key);

		do low++;
		while (ar[low] < key);

		if (low < high) 
			swap(ar, low, high);
		else 
			return high;
	}
}

int partition3(int *ar, int low, int high) 
{
	int key = ar[high];
	int last = low - 1;
	int fast;
	for (fast = low; fast <= high - 1; fast++) {
		if (ar[fast] <= key) {
			last++;
			swap(ar, last, fast);
		}
	}
	swap(ar, last + 1, high);
	return last + 1;
}

void swap(int *ar,int a, int b)
{
	int tmp = ar[a];
	ar[a] = ar[b];
	ar[b] = tmp;
}
