#ifndef ROBUSTIO_H_
#define ROBUSTIO_H_

#include "NonCopyable.h"
#include <unistd.h>

class RobustIO : NonCopyable
{
public:
	RobustIO(int fd);
	ssize_t read(char *usrbuf, size_t n);
	ssize_t readn(char *usrbuf, size_t n);
	ssize_t readLine(char *usrbuf, size_t n);
	ssize_t writen(int  fd, const void *buf, size_t n);


private:
	static const int kBufferSize = 65536;

	int fd_;
	int cnt_;
	char *ptr_;
	char buffer_[kBufferSize];
};

#endif //ROBUSTIO_H_