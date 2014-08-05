//The max and second number

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main(int argc, char * argv[]) {
	srand(time(NULL));
	int ar[N];
	int i, j;
	for (i = 0; i < N; i++)
		ar[i] = rand() % 100;

	for (i = 0; i < N; i++)
		printf("%3d", ar[i]);

	printf("\n");

	int max = 0;
	int second = 0;

	for(i = 0; i < N; i++) {
		if (ar[i] > max) {
			second = max;
			max = ar[i];
		} else if (second < ar[i] && ar[i] != max) {
			second = ar[i];
		}
	}

	printf("the max = %d, second max = %d\n",max, second);

	return 0;
}
