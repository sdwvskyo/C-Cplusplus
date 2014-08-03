/*
题目:有一个已经排好序的数组。现输入一个数,要求按原来的规律将它插入数组中。
*/

#include <stdio.h>
#define N 11

void printA(int *a, int n) {
	for(int i = 0; i < n; i++)
		printf("%4d", a[i]);
	printf("\n");
}

int main(int argc, char *argv[]) {
	
	int ar[N] = {1,4,5,9,13,16,19,28,40,100};
	printA(ar, N -1 );
	printf("Enter a numbber to insert: \n");
	int num;
	scanf("%d", &num);
	int i = 0;
	while (ar[i] < num)
		i++;
	if (i <= 9) {
		for (int k = N - 1; k >= i; k--)
			ar[k + 1] = ar[k];
		ar[i] = num;
	} else 
		ar[10] = num;

	printA(ar, N);

	return 0;
}
