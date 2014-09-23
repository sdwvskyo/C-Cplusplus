#include "date.h"

using namespace std;

int main(int argc, const char *argv[])
{
	Date date;
	date.setNow();
	date.showTime();
	date.showTimeByEnglish();
	return 0;
}
