//两个数组的交集和并集


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void creat(int ar[], int n);
void print(int ar[], int n);
int common(int a[], int b[], int c[], int d[]);
int bingji(int a[], int b[], int c[], int d[]);
void sort(int ar[], int n);

int main(int argc, char * argv[]) {
	srand(time(NULL));
	int a[N];
	int b[N];
	int c[N];
	int d[3 * N];

	creat(a, N);
	creat(b, N);
	creat(c, N);
	sort(a, N);
	sort(b, N);
	sort(c, N);
	print(a, N);
	print(b, N);
	print(c, N);

	int len = common(a, b, c, d);
	printf("交集:\n");
	print(d, len);
	len = bingji(a, b, c, d);
	printf("并集:\n");
	print(d, len);
	return 0;
}

int common(int a[], int b[], int c[], int d[]) {
	int len1 = N;
 	int len2 = N;
	int len3 = N;
	int index1 = 0;
	int index2 = 0;
	int index3 = 0;
	int index4 = 0;
	while(index1 < len1 && index2 < len2 && index3 < len3) {
		if(a[index1] == b[index2] || a[index1] == c[index3] || b[index2] == c[index3]) {
			if(a[index1] == b[index2] && a[index1] == c[index3] && b[index2] && c[index3]) {
				d[index4++] = a[index1++];
				index2++;
				index3++;
			} else if(a[index1] == c[index3]) {
				index1++;
				index3++;
			} else if(b[index2] == c[index3]) {
				index2++;
				index3++;
			} else {
				index1++;
				index2++;
			}
		} else if(a[index1] < b[index2] && a[index1] < c[index3]) {
			index1++;
		} else if(b[index2] < a[index1] && b[index2] < c[index3]) {
			index2++;
		} else {
			index3++;
		}
	}
	return index4;
}

int bingji(int a[], int b[], int c[], int d[]) {
	int len1 = N;
 	int len2 = N;
 	int len3 = N;
	int index1 = 0;
	int index2 = 0;
	int index3 = 0;
	int index4 = 0;
	while(index1 < len1 && index2 < len2) {
		if(a[index1] == b[index2] || a[index1] == c[index3] || b[index2] == c[index3]) {
			if(a[index1] == b[index2] && a[index1] == c[index3] && b[index2] && c[index3]) {
				index1++;
				index2++;
				index3++;
			} else if(a[index1] == c[index3]) {
				index1++;
				index3++;
			} else if(b[index2] == c[index3]) {
				index2++;
				index3++;
			} else {
				index1++;
				index2++;
			}
		} else if(a[index1] < b[index2] && a[index1] < c[index3]) {
			d[index4++] = a[index1++];
		} else if(b[index2] < a[index1] && b[index2] < c[index3]) {
			d[index4++] = b[index2++];
		} else {
			d[index4++] = c[index3++];
		}
	}

	while(index1 < len1)
		d[index4++] = a[index1++];
	while(index2 < len2)
		d[index4++] = b[index2++];
	while(index3 < len3)
		d[index4++] = c[index3++];

	return index4;
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


