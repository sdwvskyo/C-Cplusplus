#include "Date.h"

using namespace std;

Date::Date(int year, int month, int day)
	:year_(year), month_(month), day_(day)
{  }

Date::~Date()
{  }

bool Date::isLeapYear(int year)
{
	return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
}

//判断输入数据是否合法
static bool valueIsValid(int year, int month, int day)
{
	if (year < 1 || day < 1 || month < 1 || month > 12)
		return false;

	switch(month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day > 31)
				return false;
		case 2:
			if (Date::isLeapYear(year)) {
				if (day > 29)
					return false;
			} else {
				if (day > 28)
					return false;
			}
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30)
				return false;
		default: break;
	}
	return true;
}

//设置时间
void Date::setDate(int year, int month, int day)
{
	if (valueIsValid(year, month, day)) {
		year_ = year;
		month_ = month;
		day_ = day;
	}
}

void Date::setToday()
{
	struct tm *localTime;
	time_t t;
	t = time(NULL);
	localTime = localtime(&t);

	year_ = localTime->tm_year + 1900;
	month_ = localTime->tm_mon + 1;
	day_ += localTime->tm_mday;
}

string Date::toString() const
{
	char buf[32];
	memset(buf, 0, sizeof buf);
	snprintf(buf, sizeof buf, "%d/%d/%d", year_, month_, day_);

	string result(buf);
	return result;
}

string Date::toFormatString() const
{
	vector<string> monthName;
	monthName.push_back("NULL");
	monthName.push_back("January");
	monthName.push_back("Febeuary");
	monthName.push_back("March");
	monthName.push_back("April");
	monthName.push_back("May");
	monthName.push_back("June");
	monthName.push_back("July");
	monthName.push_back("Augurst");
	monthName.push_back("September");
	monthName.push_back("October");
	monthName.push_back("November");
	monthName.push_back("December");

	char buf[32];
	memset(buf, 0, sizeof buf);
	snprintf(buf, sizeof buf, "%s %d %d", 
			monthName[month_].c_str(), day_, year_);

	string result(buf);
	return result; 
}

bool Date::isLeapYear() const
{
	return (year_%4 == 0 && year_%100 != 0) || (year_ % 400 == 0);
}

int Date::calDayOfYear() const
{
	int sum = 0;
	for (int i = 1; i < month_; i++) {
		sum += 31;
		switch(i) {
			case 2:
				if (isLeapYear(year_))
					sum -= 2;
				else
					sum -= 3;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				sum -= 1;
				break;
			default: break;
		}
	}
	return sum + day_;
}

int Date::differenceDate(const Date &d1, const Date &d2)
{
	int result = 0;
	int bigerYear = d1.year_ > d2.year_ ? d1.year_ : d2.year_;
	int smallerYear = d1.year_ < d2.year_ ? d1.year_ : d2.year_;
	for (int i = smallerYear; i < bigerYear; i++) {
		if (isLeapYear(i))
			result += 366;
		else
			result += 365;
	}
	int tmp = d1.calDayOfYear() - d2.calDayOfYear();
	tmp = d1.year_ > d2.year_ ? tmp : -tmp;
	result += tmp;
	result = d1.year_ > d2.year_ ? result : -result;
	return result;
}

Date Date::today()
{
	Date date;
	date.setToday();
	return date;
}
