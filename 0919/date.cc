#include "date.h"

Date::Date()
{

}

Date::~Date()
{

}

void Date::setNow()
{
	time_t t;
	t = time(NULL);
	struct tm *result;
	result = localtime(&t);

	year_ = result->tm_year + 1900;
	month_ = result->tm_mon + 1;
	day_ = result->tm_mday;
	hour_ = result->tm_hour;
	minute_ = result->tm_min;
	second_ = result->tm_sec;
}

void Date::showTime()
{
	using std::cout;
	using std::endl;
	cout << year_ << '/' << month_ << '/' << day_ << ' ';
	cout << hour_ << ':' << minute_ << ':' << second_ << endl;
}

void Date::showTimeByEnglish()
{
	using std::endl;
	using std::cout;

	std::vector<std::string> months;
	months.push_back("December");
	months.push_back("January");
	months.push_back("February");
	months.push_back("March");
	months.push_back("April");
	months.push_back("May");
	months.push_back("June");
	months.push_back("July");
	months.push_back("August");
	months.push_back("September");
	months.push_back("October");
	months.push_back("November");

	setNow();
	cout << months[month_] << ' ' << day_ << ' ' << year_ << ' ';
	cout << hour_ << ':' << minute_ << ':' << second_ << endl;
}
