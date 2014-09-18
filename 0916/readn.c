#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

/*
 * -1代表出错
 * 0代表fd结束
 * count代表读满
 * 0 < count < n 代表中间遇到EOF
 *
 * readn提供了一种保证，如果不出错而且fd有数据可读，那么一定读满n个字节
 */
size_t readn(int fd, void *buf, size_t count)
{
	assert(fd > 0 && buf != NULL);

	size_t nleft = count;
	size_t nread = 0;
	char *bufp = (char *)buf;
	
	while (nleft > 0) {
		nread = read(fd, bufp, nleft);
		if (nread == -1) {
			if (errno == EINTR) 
				continue;
			else 
				return -a;
		}
		nleft -= nread;
		bufp += nread;
	}
	return count - nleft;
}

/*
 * -1出错
 * count写满
 * writen只有这两个返回值
 * 保证fd不关闭，则写满count个字节
 */
size_t writen(int fd, void *buf, size_t count)
{
	assert(fd > 0 && buf != NULL);

	size_t nleft = 0;
	size_t nwrite = 0;
	const char *bufp = (const char *)buf;

	while (nleft > 0) {
		nwrite = write(fd, bufp, nleft);
		if (nwrite <= 0) {
			if (nwrite == -1 && errno == EINTR)
				continue;
			else
				return -1;
		}
		nleft -= nwrite;
		bufp += nwrite;
	}
	return count;
}


bool isBig_Endian()
{
	unsigned short test = 0x1234;
	if (*(unsigned char *)&test == 0x12) {
		return true;
	} else {
		return false;
	}
}

