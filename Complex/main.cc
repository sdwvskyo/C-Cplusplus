#include "Complex.h"
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, const char *argv[])
{
	Complex c1(1, 1);
	cout << c1 << endl;
	Complex c2 = c1;
	cout << c2 << endl;
	cout << c1 + c2 << endl;

	Complex c3(c1+c2);
	cout << c3 << endl;
	cout << c3.getMod() << endl;
	return 0;
}
