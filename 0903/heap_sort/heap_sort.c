/*************************************************************************
	> File Name: heep_sort.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  9/ 3 10:08:04 2014
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void heap_sort(int *ar, int len);
void heap_adjust(int *ar, int pos, int len);
void swap(int *ar, int a, int b);
int * createArr(int len);
void printArr(int *ar, int len);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("argument less\n");
		exit(1);
	}
	srand(getpid());
	int len = atoi(argv[1]);
	int *ar = createArr(len);
	printArr(ar, len);
	heap_sort(ar, len);
	printArr(ar, len);
	return 0;
}

void heap_sort(int *ar, int len)
{
	int i;
	for (i = len / 2 - 1; i >= 0; i--) {
		heap_adjust(ar, i, len - 1);
	}

	for (i = len - 1; i > 0; i--) {
		swap(ar, 0, i);
		heap_adjust(ar, 0, i - 1);
	}
}

void heap_adjust(int *ar, int i, int end) 
{
	int key = ar[i];
	int j;
	for (j = (i * 2) + 1; j <= end; j = j * 2 + 1) {
		if (j < end && ar[j] < ar[j + 1]) {
			j++;
		}
		if (key >= ar[j]) {
			break;
		}
		ar[i] = ar[j];
		i = j;
	}
	ar[i] = key;
}

void printArr(int *ar, int len)
{
	for (int i = 0; i < len; i++) {
		printf("%5d", ar[i]);
	}
	printf("\n");
}

int * createArr(int len)
{
	int *ar = (int *)calloc(len, sizeof(len));
	for (int i = 0; i < len; i++) {
		ar[i] = rand() % 10000;
	}
	return ar;
}

void swap(int *ar, int a, int b)
{
	int tmp = ar[a];
	ar[a] = ar[b];
	ar[b] = tmp;
}
