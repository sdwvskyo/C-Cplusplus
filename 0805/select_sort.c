//select sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void selectSort(int ar[], int n);
void creat(int ar[], int n);
void print(int ar[], int n);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int ar[N];
	creat(ar, N);
	print(ar, N);
	selectSort(ar, N);
	print(ar, N);
	return 0;
}

void selectSort(int ar[], int n) {
	int i, j;
	int min;
	for(i = 0; i < n - 1; i++) {
		min = i;
		for(j = i; j < n; j++) {
			if (ar[min] > ar[j])
				min = j;
		}
		int tmp = ar[i];
		ar[i] = ar[min];
		ar[min] = tmp;
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
