#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
	int *ar = new int[1000000];
	for (int i = 0; i < 1000000; i++) {
		cout << ar[i] << " ";
	}
	return 0;
}
