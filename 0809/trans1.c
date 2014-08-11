#include <stdio.h>

int main() {
	int a, m;
	printf("Which you want to transform: \n");
	while (scanf("%d", &m) != EOF) {
		if (0 == m) 
			break;
		printf("Enter a number to transform: \n");
		scanf("%d", &a);

		int buf[100];
		int size = 0;

		while (a > 0) {
			buf[size++] = a % m;
			a /= m;
		}

		for (int i = size - 1; i >= 0; i--)
			printf("%d", buf[i]);

		printf("\n");
	}

	return 0;
}
