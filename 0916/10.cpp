#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

void deletePunct1(string &s)
{
	for (size_t i = 0; i < s.size(); ++i) {
		if (ispunct(s[i]))
			s[i] = ' ';
	}
}

string deletePunct(string &s)
{
	string result = "";
	for (string::iterator it = s.begin();
			it != s.end();
			++it)
	{
		if (!ispunct(*it))
			result += *it;
	}
	return result;
}

int main(int argc, const char *argv[])
{
	string s;
	while (cin >> s) {
		cout << deletePunct(s) << endl;
	}
	return 0;
}
