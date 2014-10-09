#include <iostream>
#include <string>
#include <assert.h>
#include "CounterPtr.hpp"

using namespace std;

class Test
{
public:
	Test() { cout << "Test" << endl; }
	~Test() { cout << "~Test" << endl; }
private:
	Test(const Test &);
	Test & operator=(const Test &);
};


int main(int argc, const char *argv[])
{
	CounterPtr<Test> ptr(new Test);
	cout << ptr.getCount() << endl;

	CounterPtr<Test> ptr2(ptr);
	cout << ptr.getCount() << endl;

	CounterPtr<Test> ptr3;
	ptr3 = ptr2;
	cout << ptr3.getCount() << endl;

	if (ptr) {
		cout << "ptr is not NULL" << endl;
	}


	return 0;
}
