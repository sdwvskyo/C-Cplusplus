#include <iostream>
#include <string>
#include <vector>

using namespace std;

string integerToString(int a)
{
	string s = "";
	while (a != 0) {
		s = (char)((a % 10) + '0') + s;
		a /= 10;
	}

	return s;
}

int main(int argc, const char *argv[])
{
	int a;
	while (cin >> a) {
		cout << integerToString(a) << endl;
	}
	return 0;
}
