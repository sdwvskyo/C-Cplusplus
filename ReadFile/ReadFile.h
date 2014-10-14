#ifndef READFILE_H_
#define READFILE_H_ 

#include <string>
#include "NonCopyable.h"
#include "RobustIO.h"

class ReadFile : NonCopyable
{
public:
	explicit ReadFile(const std::string &filename);
	~ReadFile();

	bool open();

	ssize_t read(char *usrbuf, size_t count);
	ssize_t readn(char *usrbuf, size_t count);
	ssize_t readLine(char *usrbuf, size_t maxlen);

	int readInt();
	int32_t readInt32();
	int64_t readInt64();
	std::string readLine();

	void close();

private:
	int fd_;
	std::unique_ptr<RobustIO> buffer_;
	const std::string filename_;
};

#endif  /*READFILE_H_*/
