/*************************************************************************
	> File Name: euid.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  8/20 10:51:01 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <sys/types.h>
#include <grp.h>

int main(int argc, char *argv[])
{
	printf("pid: %u\ngid: %u\nusrname: %s\ngroupname: %s\neuid: %s\n", 
			getpid(), getgid(), getpwuid(getuid())->pw_name, getgrgid(getgid())->gr_name, getpwuid(geteuid())->pw_name);
	while (1) {
		printf("sleep\n");
		sleep(1);
	}
	return 0;
}
