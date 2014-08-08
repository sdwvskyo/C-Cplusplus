#include <stdio.h>

int main(int argc, char *argv[])
{
	int a[10][10];
	printf("%p\n%p\n%p\n", a, a[0], *(a+0));
	printf("%p\n%p\n%p\n", a+1, a[1], *(a+1));
	return 0;
}
