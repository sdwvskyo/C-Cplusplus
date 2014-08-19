/*************************************************************************
	> File Name: main.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/19 15:45:05 2014
 ************************************************************************/

#include "readdir.h"

int main(int argc, char *argv[])
{
	char *path = ".";
	if (argc >= 2) {
		path = argv[1];
	}

	DIR *dp = opendir(path);
	if (dp == NULL) {
		perror("Open file");
		exit(1);
	}
	chdir(argv[1]);
	struct dirent *dirbuf;
	struct stat statbuf;
	char *filename[N];
	int index = 0;
	while ((dirbuf = readdir(dp)) != NULL) {
		if ((strcmp(dirbuf->d_name, ".") == 0) || (strcmp(dirbuf->d_name, "..") == 0)) {
			continue;
		}
		filename[index] = (char *)calloc(strlen(dirbuf->d_name), sizeof(char));
		strcpy(filename[index], dirbuf->d_name);
		index++;
	}
	qsort(filename, index - 1, sizeof(filename[0]), cmp);
	for (int i = 0; i < index; i++) {
		printInfo(filename[i]);
	}
	closedir(dp);
	return 0;
}

