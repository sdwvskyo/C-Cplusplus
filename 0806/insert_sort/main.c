//insert sort
#include "insert.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int ar[N];
	creat(ar, N);
	print(ar, N);
	insertSort(ar, N);
	print(ar, N);
	return 0;
}

