#include "Date.h"

using namespace std;

int main(int argc, const char *argv[])
{
	Date date;

	date.setToday();
	cout << date.toString() << endl;
	cout << date.calDayOfYear() << endl;

	cout << "------------------" << endl;
	Date date2(2013, 10, 1);
	cout << date2.toString() << endl;
	cout << date2.calDayOfYear() << endl;
	
	cout << Date::differenceDate(date, date2) << endl;
	
	return 0;
}
