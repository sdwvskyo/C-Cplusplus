//shell sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void shellSort(int ar[], int n);
void creat(int ar[], int n);
void print(int ar[], int n);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int ar[N];
	creat(ar, N);
	print(ar, N);
	shellSort(ar, N);
	print(ar, N);
	return 0;
}

void shellSort(int ar[], int n) {
	int key;
	int i, j, k;
	k = n / 2;
	while(k > 0) {
		for(i = k; i < n; i++) {
			key = ar[i];
			j = i - k;
			while(j >= 0 && key < ar[j]) {
				ar[j + k] = ar[j];
				j -= k;
			}
			ar[j + k] = key;
		}
		k /= 2;
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
