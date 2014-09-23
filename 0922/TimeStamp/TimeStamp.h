#ifndef TIMESTAMP_H
#define TIMESTAMP_H 

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <sys/time.h>

#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif /* __STDC_FORMAT_MACROS */
#include <inttypes.h>

class TimeStamp{
	public:
		TimeStamp();
		TimeStamp(int64_t usec);
		~TimeStamp();

		int64_t getTime();
		std::string toString() const;
		std::string toFormatString() const;
		static TimeStamp now();
	private:
		int64_t usec_;
};

#endif  /*TIMESTAMP_H*/
