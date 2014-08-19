/*************************************************************************
	> File Name: readDir.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/19 10:53:07 2014
 ************************************************************************/


#include "readdir.h"

int cmp(const void *a, const void *b)
{
	return (strcmp(*(char **)a, *(char **)b));
}

void printInfo(char *name)
{
	struct stat st;	
	if (lstat(name, &st) < 0) {
		perror("get stat: ");
		exit(1);
	}
	char dest[11];
	modeToStr(st.st_mode, dest);
	char atime[30];
	timeWithoutSec(st.st_mtime, atime);
	struct passwd *uid = getpwuid(st.st_uid);
	struct group *gid = getgrgid(st.st_gid);	
	printf("%7llu %s %3u %-6s%-6s%6llu %s %s\n" , st.st_ino, dest, st.st_nlink, uid->pw_name, 
			gid->gr_name, st.st_size, atime, name);
}

