#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int comp(const void *left, const void *right) 
{
	return *(int *)left -  *(int *)right;
}

int main(int argc, char *argv[]) 
{
	srand(time(NULL));
	int i;
	int ar[N];
	for (i = 0; i < N; i++) {
		ar[i] = rand() % 10000;
		printf("%d\t", ar[i]);
	}
	putchar('\n');
	qsort(ar, N, sizeof(int), comp);

	for (i = 0; i < N; i++) {
		printf("%d\t", ar[i]);
	}
	putchar('\n');

	return 0;
}
