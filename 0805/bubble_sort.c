//用两种方法实现冒泡排序

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void bubble1(int ar[], int n); //单向冒泡
void bubble2(int ar[], int n); //双向冒泡 
void creat(int ar[], int n); //创建数组
void print(int ar[], int n); //打印数组
void swap(int *a, int *b);

int swapCnt = 0;
int cmpCnt = 0;

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int ar[N];

	//单向冒泡
	creat(ar, N);
	print(ar, N);
	bubble1(ar, N);
	print(ar, N);

	//双向冒泡
	creat(ar, N);
	print(ar, N);
	bubble2(ar, N);
	print(ar, N);

	return 0;
}

void bubble2(int ar[], int n) {
	int start = 0;
	int end = n - 1;
	int flag = 1;
	int index;
	while(start < end && flag) {
		flag = 0;
		for(index = start; index < end; index++) {
			if((++cmpCnt) && ar[index] > ar[index + 1]) {
				swap(&ar[index], &ar[index + 1]);
				flag = 1;
				swapCnt++;
			}
		}
		start++;
		if(start >= end) {
			break;
		}
		for(; index >= start; index--) {
		   if((++cmpCnt) && ar[index] < ar[index - 1]) {
			   swap(&ar[index], &ar[index -1]);
			   swapCnt++;
			   flag = 1;
		   }
		}
		end--;
	}
}


void bubble1(int ar[], int n) {
	int i, j;
	int flag = 1;
	for(i = 0; (i < n - 1) && flag; i++) {
		flag = 0;
		for(j = 0; j < n - i - 1; j++) {
			if((++cmpCnt) && ar[j] > ar[j + 1]) {
				swap(&ar[j], &ar[j + 1]);
				flag = 1;
				swapCnt++;
			}
		}
	}
}

void creat(int ar[], int n) {
	swapCnt = 0;
	cmpCnt = 0;
	for(int i = 0; i < n; i++)
		ar[i] = rand() % 100;
}

void print(int ar[], int n) {
	for(int i = 0; i < n; i++)
		printf("%-3d", ar[i]);
	printf("\n");
	if(cmpCnt != 0)
		printf("比较了: %d 次，交换了: %d 次.\n", cmpCnt, swapCnt);
}

void swap(int *a, int *b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
