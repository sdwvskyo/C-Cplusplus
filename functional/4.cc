#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

using namespace placeholders;

void test(int i, double d, const string &s)
{
	cout << "i = " << i << "d = " << d << "s = " << s << endl;
}


int main(int argc, const char *argv[])
{
	function<void (int, double, const string &)> f = &test;
	f(12, 3.14, "foo");

	function<void (int, double)> f1 = bind(&test,
										   _1,
										   _2,
										   "foo");
	f1(55, 6.6);

	function<void (double, int, const string &)> f2 = bind(&test,
														   _2,
														   _1,
														   _3);
	f2(9.9, 999, "hahah");

	function<void (const string &, int)> f3 = bind(&test, 
												   std::placeholders::_2,
												   0.0,
												   std::placeholders::_1);
	f3("asd", 100);

	function<void (const string &, int, double)> f4 = bind(&test,
														   _2,
														   _3,
														   _1);
	
	function<void (int)> f5 = bind(&test, _1, 0.0, "bar");
	function<void (const string &)> f6 = bind(&test, 10, 0.0, _1);
	function<void ()> f7 = bind(&test, 33, 3.14, "asdadqw");
	return 0;
}
