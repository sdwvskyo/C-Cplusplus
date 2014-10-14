#include "ReadFile.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

using namespace std;

ReadFile::ReadFile(const string &filename)
	: fd_(-1), filename_(filename)
{
	open();
}


ReadFile::~ReadFile()
{
	if (fd_ != -1)
		close();
}

bool ReadFile::open()
{
	fd_ = ::open(filename_.c_str(), O_RDONLY);
	if (fd_ == -1)
		return false;
	buffer_.reset(new RobustIO(fd_));
	return true;
}

ssize_t ReadFile::read(char *usrbuf, size_t count)
{
	return buffer_->read(usrbuf, count);
}

ssize_t ReadFile::readn(char *usrbuf, size_t count)
{
	return buffer_->readn(usrbuf, count);
}

ssize_t ReadFile::readLine(char *usrbuf, size_t maxlen)
{
	return buffer_->readLine(usrbuf, maxlen);
}

int ReadFile::readInt()
{
	int buf;
	buffer_->readn((char *)&buf, sizeof(int));
	return buf;
}

int32_t ReadFile::readInt32()
{
	int32_t buf;
	buffer_->readn((char *)&buf, sizeof(int32_t));
	return buf;
}

int64_t ReadFile::readInt64()
{
	int64_t buf;
	buffer_->readn((char *)&buf, sizeof(int64_t));
	return buf;
}

string ReadFile::readLine()
{
	char buf[1024];
	readLine(buf, 1024);
	return string(buf);
}

void ReadFile::close()
{
	::close(fd_);
	fd_ = -1;
}