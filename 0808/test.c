#include <stdio.h>



int main(int argc, char *argv[]) 
{
	char a;
	a = 98;
	printf("sizeof: %lu, a = %d\n", sizeof(++a), a);
	return 0;	
}
