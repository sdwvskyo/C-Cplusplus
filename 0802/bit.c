#include <stdio.h>
#define ISSET (a, n) a & (1 << n)

int main(void) {
	int a;
	while(scanf("%d", &a) == 1) {
		int i = 0;
		int cnt = 0;
		for (i = 0; i < 32; i++)
		if (ISSET(a, i))
			cnt++;
		printf("%d has %d ge 1\n",a, cnt);
	}
	return 0;
}


void swap(int *a, int *b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//a ^ a = 0;
 a ^ 0 = a;
