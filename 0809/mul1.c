#include <stdio.h>

int main() {
	int a, b;
	printf("Enter two numbers: \n");
	scanf("%d%d",&a, &b);
	int buf1[20], buf2[20];
	int size1, size2;

	while(a > 0) {
		buf1[size1++] = a % 10;
		a /= 10;
	}

	while(b > 0) {
		buf2[size2++] = b % 10;
		b /= 10;
	}
	int result = 0;
	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size2; j++) {
			result += buf1[i] * buf2[j];
		}
	printf("The result i : %d.\n",result);
	return 0;
}
