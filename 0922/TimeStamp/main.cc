#include "TimeStamp.h"

using namespace std;

int main(int argc, const char *argv[])
{
	TimeStamp ts;
	cout << ts.toString() << endl;
	cout << ts.toFormatString() << endl;
	return 0;
}
