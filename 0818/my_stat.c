/************************************************************************
	> File Name: my_stat.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  8/18 15:43:15 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <uuid/uuid.h>
#include <pwd.h>
#include <grp.h>

void modeToStr(mode_t mode, char *dest);
void timeWithoutSec(time_t src_time, char *dst_time);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("argument miss.\n");
	}
	struct stat st;	
	if (stat(argv[1], &st) < 0) {
		perror("get stat: ");
		exit(1);
	}
	char dest[11];
	modeToStr(st.st_mode, dest);
	char atime[30];
	timeWithoutSec(st.st_atime, atime);
	struct passwd *uid = getpwuid(st.st_uid);
	struct group *gid = getgrgid(st.st_gid);	
	printf("%llu %s  %u %s  %s %5llu %s %s\n" , st.st_ino, dest, st.st_nlink, uid->pw_name, 
			gid->gr_name, st.st_size, atime, argv[1]);
	return 0;
}

void modeToStr(mode_t mode, char *dest)
{
	strcpy(dest, "-rwxrwxrwx");
	int tmp = 1 << 8;
	int index = 1;
	while(index < strlen(dest)) {
		if (!(mode & tmp)) {
			dest[index] = '-';
		}
		index++;
		tmp >>= 1;
	}
	if (S_ISDIR(mode)) {
		dest[0] = 'd';
	} else if (S_ISLNK(mode)) {
		dest[0] = 'l';
	} 
}
void timeWithoutSec(time_t src_time, char *dst_time)
{
	char *tmp = ctime(&src_time);
	while (*tmp++ != ' ')
		;
	int high = strlen(tmp);
	while(tmp[high] != ':') {
		high--;
	}
	tmp[high] = '\0';
	strcpy(dst_time, tmp);
}
