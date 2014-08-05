//heap sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void heapAdjust(int ar[], int start, int end);
void heapSort(int ar[], int n);
void creat(int ar[], int n);
void print(int ar[], int n);
void swap(int *a, int *b);

int main(int argc, char *argv[]) {
	int ar[N];
	srand(time(NULL));
	creat(ar, N);
	print(ar, N);
	heapSort(ar, N);
	print(ar, N);

	return 0;
}

void heapSort(int ar[], int n) {
	int i, j;
	for(i = n / 2; i > 0; i--)
		heapAdjust(ar, i, n - 1);

	for(i = n - 1; i > 0; i--) {
		swap(&ar[i], &ar[1]);
		heapAdjust(ar, 1, i - 1);
	}
}

void heapAdjust(int ar[], int start, int end) {
	int i;
	int key = ar[start];
	for(i = start * 2; i < end; i *= 2) {
		if(i < end && ar[i] < ar[i + 1])
			i++;
		if(key > ar[i])
			break;
		ar[start] = ar[i];
		start = i;
	}
	ar[start] = key;
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void creat(int ar[], int n) {
	for(int i = 1; i < n; i++)
		ar[i] = rand() % 100;
}

void print(int ar[], int n) {
	for (int i = 1; i < n; i++) 
		printf("%-3d", ar[i]);
	printf("\n");
}
