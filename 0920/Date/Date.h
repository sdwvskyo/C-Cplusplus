#ifndef DATE_H__
#define DATE_H__ 
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdexcept>

using std::string;

class Date {
	public:
		Date(int year = 1, int month = 1, int day = 1);
		~Date();

		void setDate(int year, int month, int day);
		void setToday();
		string toString() const;
		string toFormatString() const;
		bool isLeapYear() const;
		int calDayOfYear() const;

		static int differenceDate(const Date &d1, const Date &d2);
		static Date today();
		static bool isLeapYear(int year);
	private:
		int year_;
		int month_;
		int day_;
};


#endif  /*DATE_H__*/
