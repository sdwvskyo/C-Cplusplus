#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void swift(string &str)
{
	for (size_t i = 0; i < str.size(); i++) {
		if (islower(str[i]))
			str[i] = toupper(str[i]);
		else if (isupper(str[i])) {
			str[i] = tolower(str[i]);
		}
	}
}

int main(int argc, const char *argv[])
{
	string s;
	while (cin >> s) {
		swift(s);
		cout << s << endl;
	}
	return 0;
}
