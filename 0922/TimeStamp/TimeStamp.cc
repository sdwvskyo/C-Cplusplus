#include "TimeStamp.h"

using namespace std;

TimeStamp::TimeStamp()
{
	usec_ = getTime();
}

TimeStamp::TimeStamp(int64_t usec)
	: usec_(usec)
{  }

TimeStamp::~TimeStamp()
{

}

int64_t TimeStamp::getTime()
{
	struct timeval tm;
	gettimeofday(&tm, NULL);
	usec_ = tm.tv_sec * 1000000 + tm.tv_usec;
	return usec_;
}

string TimeStamp::toString() const
{
	char buf[100];
	memset(buf, 0, sizeof buf);
	snprintf(buf, sizeof buf, "%lf", usec_ / (double)1000000);
	string result = buf;
	return result; 
}

string TimeStamp::toFormatString() const
{
	time_t sec = usec_ / 1000000;
	struct tm tm_time;
	localtime_r(&sec, &tm_time);
	char buf[100] = "";
	memset(buf, 0, sizeof buf);
	snprintf(buf, sizeof buf, "%04d%02d%02d %02d:%02d:%02d.%lld", 
			 tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday, 
			 tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec, usec_ % 1000000);
	string result = buf;
	return result;
}

TimeStamp TimeStamp::now()
{
	return TimeStamp();
}

