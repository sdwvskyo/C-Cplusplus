#include <stdio.h>
#include <string.h>
int main(void) {
	char ch;
	int left, right;
	while(scanf("%d%c%d", &left, &ch, &right) == 3) {
		double result = 0;
		if('+' == ch)
			result = left + right;
		else if('-' == ch)
			result = left - right;
		else if('*' == ch)
			result = right * right;
		else if('/' == ch) {
			if (right != 0)
				result = (double)left / right;
			else 
				printf("error!");
		}
		printf("The result is: %.2f\n", result);
	}
	return 0;
}


