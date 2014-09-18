#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int main(int argc, const char *argv[])
{
	int a, b;
	while (cin >> a >> b) {
		try {
			if (b == 0)
				throw(runtime_error("b can not 0"));
			else
				cout << static_cast<double>(a) / b << endl;
		} 
		catch (exception &e) {
			cout << e.what() << endl;
			char c;
			cin >> c;
			if (c == 'y')
				break;
		}
	}

	return 0;
}
