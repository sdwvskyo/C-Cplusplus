//heap sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void insertSort(int ar[], int n);
void creat(int ar[], int n);
void print(int ar[], int n);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int ar[N];
	creat(ar, N);
	print(ar, N);
	insertSort(ar, N);
	print(ar, N);
	return 0;
}

void insertSort(int ar[], int n) {
	int key;
	int i, j;
	for(i = 1; i < n; i++) {
		key = ar[i];
		for(j = i - 1; key < ar[j] && j >=0; j--) {
			ar[j + 1] = ar[j];
		}
		ar[j + 1] = key;
	}
}

void creat(int ar[], int n) {
	for(int i = 0; i < n; i++)
		ar[i] = rand() % 100;
}

void print(int ar[], int n) {
	for (int i = 0; i < n; i++) 
		printf("%-3d", ar[i]);
	printf("\n");
}
