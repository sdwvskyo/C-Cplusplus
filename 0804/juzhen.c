//将数字排列成矩形

#include <stdio.h>
#define MAX 20

void shexing(int n);
void luoxuan(int n);
void fanluoxuan(int n);

int ar[MAX][MAX];

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) == 1) {
		shexing(n);
		printf("\n\n");
		luoxuan(n);
		printf("\n\n");
		fanluoxuan(n);
		printf("\n");
	}
	return 0;
}

void shexing(int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {			
			for (j = i * n + 1; j <= n * (i + 1); j++) {
				printf("%3d", j);
			}
		} else {
			for (j = (i + 1) * n; j > i * n; j--) {
				printf("%3d", j);
			}
		}
		printf("\n");
	}

}

void luoxuan(int n) {
	int i, j;
	int sum = 1;
	for(i = 0; i <= n / 2; i++) {
		for( j = i; j < n - i; j++) {
			ar[i][j] = sum++;
		}
		for(j = i + 1; j < n - i - 1; j++) {
			ar[j][n - i - 1] = sum++;
		}
		for(j = n - i - 1; j > i; j--) {
			ar[n - i - 1][j] = sum++;
		}
		for(j = n - i -1; j > i; j--) {
			ar[j][i] = sum++;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%3d", ar[i][j]);
		}
		printf("\n");
	}
}

void fanluoxuan(int n) {
	int i, j;
	int sum = n * n;
	for(i = 0; i <= n / 2; i++) {
		for( j = n - i - 1; j >= i; j--) {
			ar[i][j] = sum--;
		}
		for(j = i + 1; j < n - i - 1; j++) {
			ar[j][i] = sum--;
		}
		for(j = i; j < n - i - 1; j++) {
			ar[n - i - 1][j] = sum--;
		}
		for(j = n - i -1; j > i; j--) {
			ar[j][n - i -1] = sum--;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%3d", ar[i][j]);
		}
		printf("\n");
	}
}

