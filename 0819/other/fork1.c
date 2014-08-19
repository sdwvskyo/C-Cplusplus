/*************************************************************************
	> File Name: fork1.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/19 20:52:57 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	char *msg;
	printf("fork program start: \n");
	pid = fork();
	int n;
	int exit_code;
	switch(pid) {
		case -1:
			perror("fork failed.\n");
			exit(1);
		case 0:
			msg = "This is the child process.\n";
			n = 7;
			return 37;
			break;
		default :
			msg = "This is the parent.\n";
			n = 3;
			exit_code = 0;
			break;
	}

	for(; n > 0; n--) {
		printf("%s", msg);
		sleep(1);
	}
	if (pid != 0) {
		pid_t child_pid;
		int start_val;
		child_pid = wait(&start_val);
		printf("child_pid: %u, pid: %u\n", child_pid, pid);
		if (WIFEXITED(start_val)) {
			printf("child exit with code: %d", WIFEXITED(start_val));
		} else {
			printf("child terminated abnormarlly.\n");
		}
	}
	return 0;
}




