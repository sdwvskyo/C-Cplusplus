#include <stdio.h>
#define N 1024

int main(void) {

	char line[N];
	int counter;
	while (1) {
		gets(line);
		if(line == NULL || line[0] == '\0')
			break;
		counter++;
		printf("%d: %s\n", counter, line);
	}

	return 0;
}
