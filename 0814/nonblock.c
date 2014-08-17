#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MSG_TRY "try again\n"

int main(int argc, char *argv[]) 
{
	char buf[10];
	int fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
	if (fd < 0) {
		perror("open /dev/tty error\n");
		exit(1);
	}
	int n;
tryagain:
	n = read(fd, buf, 10);
	if (n < 0) {
		if (errno == EAGAIN) {
			sleep(1);
			write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
			goto tryagain;
		}
		perror("read /dev/tty");
		exit(1);
	}
	write(STDOUT_FILENO, buf, n);
	close(fd);
	return 0;
}
	
