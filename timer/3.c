#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <errno.h>
#include <time.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)


void sigalrm_handler(int sig)
{
	printf("foo\n");
}

void nano_sleep(double val)
{
	struct timespec tv;
	tv.tv_sec = val;
	tv.tv_nsec = (val - tv.tv_sec) * 1000 * 1000 * 1000;

	int ret;
	do {
		ret = nanosleep(&tv, &tv);
	} while (ret == -1 && errno == EINTR);
}



int main(int argc, char const *argv[])
{
	if (signal(SIGALRM, sigalrm_handler) == SIG_ERR)
		ERR_EXIT("signal");

	nano_sleep(4.5);



	return 0;
}




