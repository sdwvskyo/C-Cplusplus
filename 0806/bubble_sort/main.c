#include "bubble.h"


int main(int argc, char *argv[]) {
	srand(time(NULL));
	int ar[N];

	//单向冒泡
	creat(ar, N);
	print(ar, N);
	bubble1(ar, N);
	print(ar, N);

	//双向冒泡
	creat(ar, N);
	print(ar, N);
	bubble2(ar, N);
	print(ar, N);

	return 0;
}
