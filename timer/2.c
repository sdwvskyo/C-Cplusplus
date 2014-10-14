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

	alarm(4);
	
	int n = 100;
	do {
		n = sleep(n);
		printf("%d\n", n);
	}while(n > 0);

	return 0;
}




