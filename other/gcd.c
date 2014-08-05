#include <stdio.h>

int gcd1(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int gcd2(int a, int b) {
	if(b == 0) return a;
	else return gcd2(b, a % b);
}

int gcd3(int a, int b) {
	int m;
	for (m = b; m > 0; m--) {
		if(a % m == 0 && b % m == 0)
			break;
	}
	return m;
}

int main() {
	int a, b;
	printf("Enter two number: \n");
	while (scanf("%d%d", &a, &b) == 2) {
		if(a == 0 || b == 0) 
			break;
		printf("gcd1: %d\n", gcd1(a, b));
		printf("gcd2: %d\n", gcd1(a, b));
		printf("gcd3: %d\n", gcd1(a, b));
	}
	return 0;
}
