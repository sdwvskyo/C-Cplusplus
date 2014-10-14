#include "RobustIO.h"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	}

RobustIO::RobustIO(int fd)
	: fd_(fd), cnt_(0), ptr_(buffer_)
{
	::memset(buffer_, 0, kBufferSize);
}


ssize_t RobustIO::read(char *usrbuf, size_t n)
{
	while (cnt_ <= 0) {
		ssize_t nread = ::read(fd_, buffer_, kBufferSize);
		if (nread == -1) {
			if (errno == EINTR)
				continue;
			return -1;
		}
		else if (nread == 0)
			return 0;

		cnt_ += nread;
		ptr_ = buffer_;
	}

	size_t cnt = (cnt_ < n) ? cnt_ : n;
	::memcpy(usrbuf, ptr_, cnt);
	ptr_ += cnt;
	cnt_ -= cnt;

	return cnt;
}

ssize_t RobustIO::readn(char *usrbuf, size_t n)
{
	size_t nleft = n;
	ssize_t nread = 0;

	while (nleft > 0) {
		nread = this->read(usrbuf, nleft);
		if (nread == -1) {
			if (errno == EINTR)
				continue;
			return -1;
		}
		else if (nread == 0)
			break;

		nleft -= nread;
		usrbuf += nread;
	}

	return n - nleft;
}

ssize_t RobustIO::readLine(char *usrbuf, size_t n)
{
	size_t nread;
	char c;
	int i;
	for (i = 0; i < n - 1; ++i) {
		nread = this->read(&c, 1);
		if (nread == -1)
			return -1;
		else if (nread == 0)
			break;

		*usrbuf++ = c;
		if (c == '\n')
			break;
	}

	*usrbuf = '\0';
	return i;
}

ssize_t RobustIO::writen(int fd, const void *usrbuf, size_t n)
{
	ssize_t nwrite = 0;
	size_t nleft = n;
	const char *bufp = (const char *)usrbuf;

	while (nleft > 0) {
		nwrite = write(fd, bufp, nleft);
		if (nwrite <= 0) {
			if (nwrite == -1 && errno == EINTR)
				continue;
			return -1;
		} 

		nleft -= nwrite;
		bufp += nwrite;
	}

	return n;
}














