#include <iostream>
#include <string>
#include "myvector.h"

using namespace std;

int main(int argc, const char *argv[])
{
	MyVector<int> vec;
	vec.add(1);
	vec.add(20);
	vec.add(99);
	cout << vec.size() << endl;
	return 0;
}
