/*************************************************************************
	> File Name: printTree.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/19 18:29:03 2014
 ************************************************************************/

#include<stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void printTree(char *name, int depth);

int main(int argc, char *argv[])
{
	if (argc >= 2) {
		printTree(argv[1], 0);
	} else {
		printTree(".", 0);
	}
	printf("Done!\n");
	return 0;
}

void printTree(char *name, int depth)
{
	DIR *pd = opendir(name);
	if (pd == NULL) {
		perror("open dir");
		exit(1);
	}
	chdir(name);
	struct dirent *dirbuf;
	struct stat st;
	while ((dirbuf = readdir(pd)) != NULL) {
		if ((strcmp(dirbuf->d_name, ".") == 0) || (strcmp(dirbuf->d_name, "..") == 0)) {
			continue;
		}
		lstat(dirbuf->d_name, &st);
		if (S_ISDIR(st.st_mode)) {
			printf("%*s%s/\n", depth, " ", dirbuf->d_name);
			printTree(dirbuf->d_name, depth + 4);
		} else {
			printf("%*s%s\n", depth, " ", dirbuf->d_name);
		}
	}
	chdir("..");
	closedir(pd);
}
