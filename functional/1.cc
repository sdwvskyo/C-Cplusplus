#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

void foo(const string &s)
{
	cout << s << endl;
}

int main(int argc, const char *argv[])
{
	void (*pFunc) (const string &) = &foo;
	pFunc("bar");

	function<void (const string&)> f = &foo;
	f("bar");
	return 0;
}
