//将两个数组合并成一个数组

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void creat(int ar[], int n);
void print(int ar[], int n);
void merge(int ar[], int start, int mid, int end);
void mergeSort(int ar[], int start, int end);

int main(int argc, char * argv[]) {
	srand(time(NULL));
	int ar[N];

	creat(ar, N);
	print(ar, N);
	mergeSort(ar, 0, N - 1);
	print(ar, N);
	return 0;
}

void mergeSort(int ar[], int start, int end) {
	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(ar, start, mid);
		mergeSort(ar, mid + 1, end);
		merge(ar, start, mid, end);
	}
}

void merge(int ar[], int start, int mid, int end) {
	int len1 = mid - start + 1;
 	int len2 = end - mid;
	int left[len1], right[len2];
	int index1, index2;
	for(index1 = 0; index1 < len1; index1++)
		left[index1] = ar[start + index1];
	for(index2 = 0; index2 < len2; index2++)
		right[index2] = ar[mid + index2 + 1];
	index1 = 0;
	index2 = 0;
	while(index1 < len1 && index2 < len2) {
		if(left[index1] < right[index2]) {
			ar[start++] = left[index1++];
		} else {
			ar[start++] = right[index2++];
		}
	}

	while(index1 < len1)
		ar[start++] = left[index1++];
	while(index2 < len2)
		ar[start++] = right[index2++];
}



void creat(int ar[], int n) {
	for (int i = 0; i < n; i++)
		ar[i] = rand() % 100;
}

void print(int ar[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%-3d", ar[i]);
	}
	printf("\n");
}


