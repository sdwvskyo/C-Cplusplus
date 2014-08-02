#include <stdio.h>

int main(void) {
	printf("int: %lu byte.\n",sizeof(int));
	printf("char: %lu byte.\n",sizeof(char));
	printf("short: %lu byte.\n",sizeof(short));
	printf("long: %lu byte.\n",sizeof(long));
	printf("float: %lu byte.\n",sizeof(float));
	printf("unsigned: %lu byte.\n",sizeof(unsigned));

	return 0;
}
