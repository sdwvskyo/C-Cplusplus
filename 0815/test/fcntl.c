#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MSG_TRY "try again!\n"

int main(void)
{
	char buf[10];
	int flag, n;
	flag = fcntl(STDIN_FILENO, F_GETFL);
	flag |= O_NONBLOCK;
	if (fcntl(STDIN_FILENO, F_SETFL, flag) == -1) {
		perror("fcntl");
		exit(1);
	}
	while ((n = read(STDIN_FILENO, buf, 10)) < 0) {
		if (errno != EAGAIN) {
			perror("read stdio");
			exit(1);
		} else {
			sleep(1);
			write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
		}
	}
	write(STDOUT_FILENO, buf, n);
	return 0;
}


