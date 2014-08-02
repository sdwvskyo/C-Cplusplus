#include <stdio.h>

int main(void) {
	int val;
	int sum = 0;
	int cnt = 0;
	while (scanf("%d", &val) == 1) {
		sum += val;
		cnt++;
	}
	if (cnt == 0)
		return;

	double avg = (double)sum / cnt;

	printf("The average of the numbers is: %.2f\n", avg);

	return 0;
}


