#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <vector>
#include <string>
#include <time.h>

class Date{
	public:
		Date();
		virtual ~Date();

		void showTime();
		void showTimeByEnglish();
		void setNow();
	private:
		int year_;
		int month_;
		int day_;
		int hour_;
		int minute_;
		int second_;
};



#endif  /*_DATE_H_*/
