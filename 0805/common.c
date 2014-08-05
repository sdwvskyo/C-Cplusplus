//两个数组的交集和并集


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 10

void creat(int ar[], int n);
void print(int ar[], int n);
int common(int a[], int b[], int c[]);
int bingji(int a[], int b[], int c[]);
void sort(int ar[], int n);

int main(int argc, char * argv[]) {
	srand(time(NULL));
	int a[M];
	int b[N];
	int c[M + N];

	creat(a, M);
	creat(b, N);
	sort(a, M);
	sort(b, N);
	print(a, M);
	print(b, N);

	int len = common(a, b, c);
	printf("交集:\n");
	print(c, len);
	len = bingji(a, b, c);
	printf("并集:\n");
	print(c, len);
	return 0;
}

int common(int a[], int b[], int c[]) {
	int len1 = M;
 	int len2 = N;
	int index1 = 0;
	int index2 = 0;
	int index3 = 0;
	while(index1 < len1 && index2 < len2) {
		if(a[index1] == b[index2]) {
			c[index3++] = a[index1++];
			index2++;
		} else if(a[index1] < b[index2]) {
			index1++;
		} else {
			index2++;
		}
	}
	return index3;
}
int bingji(int a[], int b[], int c[]) {
	int len1 = M;
 	int len2 = N;
	int index1 = 0;
	int index2 = 0;
	int index3 = 0;
	while(index1 < len1 && index2 < len2) {
		if(a[index1] == b[index2]) {
			c[index3++] = a[index1++];
			index2++;
		} else if(a[index1] < b[index2]) {
			c[index3++] = a[index1++];
		} else {
			c[index3++] = b[index2++];
		}
	}

	while(index1 < len1)
		c[index3++] = a[index1++];
	while(index2 < len2)
		c[index3++] = b[index2++];

	return index3;
}
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void sort(int ar[], int n) {
	for (int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++) {
			if(ar[j] > ar[j + 1])
				swap(&ar[j], &ar[j + 1]);
		}
	}
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


