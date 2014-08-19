/*************************************************************************
	> File Name: printdir.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  8/18 23:56:44 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void printDir(const char *dir, int depth);

int main(int argc, char *argv[])
{
	char *topdir = ".";
	if (argc >= 2) {
		topdir = argv[1];
	}

	printf("Directory scan of %s\n", topdir);
	printDir(topdir, 0);
	printf("Done!\n");

	return 0;
}

void printDir(const char *dir, int depth)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if ((dp = opendir(dir)) == NULL) {
		fprintf(stderr, "Can't open directory: %s", dir);
		return;
	}
	chdir(dir);
	while ((entry = readdir(dp)) != NULL) {
		lstat(entry->d_name, &statbuf);
		if (S_ISDIR(statbuf.st_mode)) {
			if ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0)) {
				continue;
			} else {
				printf("%*s%s/\n", depth, " ", entry->d_name);
				printDir(entry->d_name, depth + 4);
			}
		} else {
			printf("%*s%s %llu\n", depth, " ", entry->d_name, statbuf.st_size);
		}
	}
	chdir("..");
	closedir(dp);
}
