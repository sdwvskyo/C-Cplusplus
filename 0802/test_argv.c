#include <stdio.h>

int main(int argc, char *argv[]){
	int index;
	for (index = 0; index <= argc; index++)
		printf("%d: %s\n", index, argv[index]);
	return 0;
}

