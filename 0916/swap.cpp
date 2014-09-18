#include <iostream>
using namespace std;

void swap(int * &a, int * &b)
{
	int *temp = a;
	a = b;
	b = temp;
}

int main(int argc, const char *argv[])
{
	int a = 1;
	int b = 2;
	int *p1 = &a;
	int *p2 = &b;

	cout << p1 << " " << p2 << endl;
	::swap(p1, p2);
	cout << p1 << " " << p2 << endl;
	return 0;
}
