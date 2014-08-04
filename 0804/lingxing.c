/*
打印实心菱形和空心菱形
*/

#include <stdio.h>

void shixin1(int n);
void shixin2(int n);
void kongxin(int n);

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) == 1) {
		shixin1(n);
		printf("\n\n");
		shixin2(n);
		printf("\n\n");
		kongxin(n);
	}
	return 0;
}

void shixin1(int n) {
	int i, j, k;
	for (i = 0; i <= n / 2; i++) {
		for (j = n / 2 - i; j > 0; j--) {
			printf(" ");
		}
		for (k = 0; k < i * 2 + 1; k++) {
		   printf("*");
		}
		printf("\n");
	}
   for (i =1 ; i <= n / 2; i++) {	   
	   for (j = 1; j <= i; j++) {
		  printf(" ");
	   }
	   for (k = 0; k < n - i * 2; k++) {
		  printf("*");
	  }
	  printf("\n");
   }
}


void shixin2(int n) {
	int i, j, k;
	for (i = 0; i < n; i++) {
		for (j = i; j < n - 1 ; j++) {
			printf(" ");
		}
		for (k = 0; k <= i; k++) {
			printf("* ");
		}
		printf("\n");
	}
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j <= i; j++) {
			printf(" ");
		}
		for (k = i; k < n - 1 ; k++) {
			printf("* ");
		}
		printf("\n");
	}
}


void kongxin(int n) {
	int i, j, k;
	for (i = 0; i < n; i++) {
		for (j = i; j < n - 1 ; j++) {
			printf(" ");
		}
		for (k = 0; k <= i; k++) {
			if(k == 0 || k == i) {
				printf("* ");
			} else {
				printf("  ");
			}
		}
		printf("\n");
	}
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j <= i; j++) {
			printf(" ");
		}
		for (k = i; k < n - 1 ; k++) {
			if (k == i || k == n -2) {
				printf("* ");
			} else {
				printf("  ");
			}
		}
		printf("\n");
	}
}
