#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
	string s;
	string result = "";
	while (cin >> s) {
		result += s;
		result += "$";
	}
	cout << result << endl;
	return 0;
}
