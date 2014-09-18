#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>

#define ERR_EXIT(m) \
	do { \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

using namespace std;

void writeToFile(int fd, int num);

int main(int argc, const char *argv[])
{
	assert(argc == 3);
	int len = atoi(argv[2]);
	srand(len);
	int fd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd == -1)
		ERR_EXIT("open");

	for (int i = 0; i < len; i++) {
		writeToFile(fd, rand() % len);
	}
	return 0;
}

void writeToFile(int fd, int num)
{
	char buf[32];
	memset(buf, 0, 32);
	snprintf(buf, sizeof buf, "%d\n", num);
	if (write(fd, buf, strlen(buf)) == -1)
		ERR_EXIT("write");
}
