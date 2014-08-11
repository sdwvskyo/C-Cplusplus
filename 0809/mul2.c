#include <stdio.h>

int main() {
	char ch1[11], ch2[11];
	printf("Enter two numbers: \n");
	scanf("%s%s",ch1, ch2);
	int result = 0;
	for(int i = 0; ch1[i] != 0; i++)
		for (int j = 0; ch2[j] != 0; j++)
			result += (ch1[i] - '0') * (ch2[j] - '0');
	printf("The result is: %d.\n",result);

	return 0;
}
