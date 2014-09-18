#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
	string str = "";
	while (cin >> str) {
		for (int i = 0; i != str.size(); i++) {
			cout << str[i] << endl;
		}
	}
	return 0;
}
