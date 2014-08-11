#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 20;

void swap(int *a, int *b);
void creatArray(int *ar);
void printArray(int *ar);
void bubble_sort(int *ar);
void select_sort(int *ar);
void insertion_sort(int *ar);
int partition(int *ar, int left, int right);
void quick_sort(int *ar, int left, int right);
int binary_search(int *ar, int key);

int main(void) {
	int ar[MAX];
	printf("This is bubble sort: \n");
	creatArray(ar);
	printArray(ar);
	bubble_sort(ar);
	printArray(ar);

	printf("This is select sort: \n");
	creatArray(ar);
	printArray(ar);
	select_sort(ar);
	printArray(ar);

	printf("This is insertion sort: \n");
	creatArray(ar);
	printArray(ar);
	insertion_sort(ar);
	printArray(ar);

	printf("This is quick sort: \n");
	creatArray(ar);
	printArray(ar);
	quick_sort(ar, 0, MAX);
	printArray(ar);

	return 0;
}

int partition(int *ar, int left, int right) {
	int pivot = ar[left];
	while(left < right) {
		while (left < right && ar[right] >= pivot)
			right--;
		if (left < right) ar[left] = ar[right];
		while(left < right && ar[left] <= pivot)
			left++;
		if (left < right) ar[right] = ar[left];
	}
	ar[left] = pivot;
	return left;
}

void quick_sort(int *ar, int left, int right) {
	if(left >= right)
		return;
	int index = partition(ar, left, right);
	quick_sort(ar, left, index - 1);
	quick_sort(ar, index + 1, right);
}

int binary_search(int *ar, int key) {
	int mid;
	int left = 0;
	int right = MAX - 1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (key == ar[mid])
			return mid;
		else if (key > ar[mid])
			left = mid + 1;
		else if (key < ar[mid])
			right = mid - 1;
	}
	return -1;
}


void insertion_sort(int *ar) {
	int temp;
	int j;
	for (int i = 1; i < MAX; i++) {
		temp = ar[i];
		j = i -1;
		while (ar[j] > temp && j >= 0) {
			ar[j+1] = ar[j];
			j--;
		}
		ar[j+1] = temp;
	}
}


void select_sort(int *ar) {
	int min;
	for (int i = 0; i < MAX - 1; i++) {
		min = i;
		for (int j = i + 1; j < MAX; j++) {
			if (ar[min] > ar[j]) {
				min = j;
			}
		}
		if (min != i) {
			swap(&ar[min], &ar[i]);
		}
	}
}

void bubble_sort(int *ar) {
	for(int i = 0; i < MAX - 1; i ++ ) {
		for (int j = 0; j < MAX - i - 1; j++) {
			if (ar[j] > ar[j+1]) {
				swap(&ar[j], &ar[j+1]);
			}
		}
	}
}

void creatArray(int *ar) {
	int num;
	srand(time(NULL));
	for(int i = 0; i < MAX; i++) {
		num = rand() % 100;
		ar[i] = num;
	}
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void printArray(int *ar) {
	for (int i = 0; i < MAX; i++) {
		printf("%d  ", ar[i]);
	}
	printf("\n");
}
