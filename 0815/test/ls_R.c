/*************************************************************************
	> File Name: ls_R.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  8/15 21:11:43 2014
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH 1024

//apply fcn to all files in dir
void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	struct dirent *dp;
	DIR *dfd;
	if ((dfd = opendir(dir) )== NULL) {
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}
	while ((dp = readdir(dfd)) != NULL) {
		if ((strcmp(dp->d_name, ".") == 0) || (strcmp(dp->d_name, "..") == 0)) {
			continue;
		}
		if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name)) {
			fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->d_name);
		} else {
			sprintf(name, "%s/%s", dir, dp->d_name);
			(*fcn)(name);
		}
	}
	closedir(dfd);
}

//fsize: print the size and name of file "name"
void fsize(char *name)
{
	struct stat stbuf;

	if(stat(name, &stbuf) == -1) {
		fprintf(stderr, "fsize: can't access %s\n", name);
		return;
	}
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
		dirwalk(name, fsize);
	}
	printf("%8lld %s\n", stbuf.st_size, name);

}

int main(int argc, char *argv[])
{
	if (argc == 1) {
		fsize(".");
	} else {
		while (--argc > 0) {
			fsize(*++argv);
		}
	}
	return 0;
}
