#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

class Foo
{
public:
	void foo(int i) { cout << i << endl; }

	static void bar(double d) { cout << d << endl; }
};

int main(int argc, const char *argv[])
{
	Foo f;
	(mem_fun(&Foo::foo))(&f, 123);

	function<void (int)> pf = bind(&Foo::foo,
								   &f,
								   std::placeholders::_1);
	pf(345);

	return 0;
}
