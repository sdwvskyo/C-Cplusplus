#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <errno.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)


void sigalrm_handler(int sig)
{
	printf("foo\n");
}

int main(int argc, char const *argv[])
{
	if (signal(SIGALRM, sigalrm_handler) == SIG_ERR)
		ERR_EXIT("signal");

	struct timeval it_value;	//初始值
	memset(&it_value, 0, sizeof it_value);
	it_value.tv_sec = 3;
	it_value.tv_usec = 0;

	struct timeval it_interval;	//间隔值
	memset(&it_interval, 0, sizeof it_interval);
	it_interval.tv_sec = 1;
	it_interval.tv_usec = 0;

	struct itimerval val;
	val.it_value = it_value;
	val.it_interval = it_interval;

	//int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);
	if (setitimer(ITIMER_REAL, &val, NULL) == -1)
		ERR_EXIT("setitimer");

	for(;;)
		pause();

	return 0;
}




