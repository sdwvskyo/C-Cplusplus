#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Test{
	public:
		Test() {cout << "Test " << endl; }
		~Test() { cout << "~Test...." << endl; }
};

int main(int argc, const char *argv[])
{
	Test *pt = new Test;
	Test t;
	delete pt;
	return 0;
}
