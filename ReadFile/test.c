#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

#define BUFFERSIZE 65536

typedef struct
{
	int fd_;	//文件描述符
	int cnt_;	//缓冲区可用字节数
	char *ptr_;	//指向缓冲区的第一个可用字节
	char buffer_[BUFFERSIZE]; 	//缓冲区

} rio_t;

//初始化IO系统
void rio_init(rio_t *rp, int fd)
{
	rp->fd_ = fd;
	rp->cnt_ = 0;
	rp->ptr_ = rp->buffer_;
	memset(rp->buffer_, 0, BUFFERSIZE);
}


//用来替换read
ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n)
{
	//cnt小于0，表示buffer为空，执行read操作
	while (rp->cnt_ <= 0) {
		ssize_t nread = read(rp->fd_, rp->buffer_, BUFFERSIZE);
		if (nread == -1) {
			if (errno == EINTR)
				continue;
			return -1;
		} 
		else if (nread == 0) {
			return 0;
		}
		//读取后重置指针和计数器
		rp->cnt_ += nread;
		rp->ptr_ = rp->buffer_;
	}

	//buffer中有数据，读取用户要求数量或库存数量，取最小者
	int cnt = (rp->cnt_ < n) ? rp->cnt_ : n;
	memcpy(usrbuf, rp->ptr_, cnt);
	rp->ptr_ += cnt;
	rp->cnt_ -= cnt;

	return cnt;	//成功读取，返回cnt
}

ssize_t rio_readn(rio_t *rp, void *buf, size_t count)
{
	size_t nleft = count;	//剩余没有读取的字节数
	ssize_t nread = 0;	//接收读取返回值
	char *bufp = (char *)buf;	//缓冲区的偏移量

	while (nleft > 0) {
		//不再使用系统read调用
		nread = rio_read(rp, bufp, nleft);
		if (nread == -1) {
			if (errno == EINTR) 
				continue;
			return -1;
		} 
		else if (nread == 0) {
			break;
		}

		nleft -= nread;
		bufp += nread;
	}

	return count - nleft; 
}

ssize_t rio_readline(rio_t *rp, char *usrbuf, size_t maxlen)
{
	ssize_t nread;
	char c;
	int i;
	for (i = 0; i < maxlen - 1; ++i) {
		nread = rio_read(rp, &c, 1);
		if (nread == -1) 
			return -1;
		else if (nread == 0) 
			break;
		//放入usrbuf
		*usrbuf++ = c;
		if (c == '\n')
			break;
	}
	*usrbuf = '\0';
	return i;
}

ssize_t rio_writen(int fd, const void *buf, size_t count)
{
	size_t nleft = count;
	ssize_t nwrite = 0;
	const char *bufp = (const char *)buf;

	while(nleft > 0) {
		nwrite = write(fd, bufp, nleft);
		if (nwrite <= 0) {
			if (nwrite == -1 && errno == EINTR)
				continue;
			return -1;
		}   
		nleft -= nwrite;
		bufp += nwrite;
	}
	return count - nleft;
}

int main(int argc, char const *argv[])
{
	int fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		ERR_EXIT("open test.txt");
	rio_t rio;
	rio_init(&rio, fd);

	char buf[1024] = "0";

	while (rio_readline(&rio, buf, sizeof buf)) {
		printf("%s", buf);
	}

	close(fd);

	return 0;
}




















