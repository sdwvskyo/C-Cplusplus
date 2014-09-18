#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
	int n;
	int count = 0;

	while (cin >> n) {
		cout << n << endl;
		count += n;
	}

	cout << count << endl;

	return 0;
}
