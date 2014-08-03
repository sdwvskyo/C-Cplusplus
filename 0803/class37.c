/*
【程序 37】题目:对 10 个数进行排序
*/

#include <stdio.h>
#define N 10

int main(int argc, char *argv[]) {
	int ar[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &ar[i]);

	for (int i = 0; i < N - 1; i++) {
		int min = i;
		for (int j = i + 1; j < N; j++)
			if (ar[j] < ar[min])
				min = j;
		int tmp = ar[i];
		ar[i] = ar[min];
		ar[min] = tmp;
	}

	for (int i = 0; i < N; i++) 
		printf("%d\t", ar[i]);
	return 0;
}

