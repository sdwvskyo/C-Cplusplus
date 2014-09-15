/*************************************************************************
	> File Name: find.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  9/11 19:40:52 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <assert.h>

#define N 1024

void traverDir(char *dir, char *str);
int findStr(char *filename, char *str);
int indexStr(char *line, char *str);

int main(int argc, char *argv[])
{
	assert(argc == 3);
	traverDir(argv[1], argv[2]);
	printf("Done!\n");
	return 0;
}

void traverDir(char *dir, char *str)
{
	DIR *dp = opendir(dir);
	if (dp == NULL) {
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	chdir(dir);
	struct dirent *ent;
	struct stat st;
	while ((ent = readdir(dp)) != NULL) {
		if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
			continue;
		}
		if (lstat(ent->d_name, &st) < 0) {
			perror("lstat");
			exit(EXIT_FAILURE);
		}
		if (S_ISDIR(st.st_mode)) {
			traverDir(ent->d_name, str);
		} else {
			if (findStr(ent->d_name, str)) {
			}
		}
	}
	chdir("..");
	closedir(dp);
}

int findStr(char *filename, char *str)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	char line[N];
	while (memset(line, 0, N), fgets(line, N, fp) != NULL) {
		if (strstr(line, str)) {
			printf("%s/%s:%s", getcwd(NULL, 0), filename, line);
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}

int indexStr(char *line, char *str)
{
	assert(line != NULL && str != NULL);
	int i = 0;
	int j = 0;
	while (line[i] != '\0' && str[j] != '\0') {
		if (line[i] == str[j]) {
			i++;
			j++;
		} else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (str[j] == '\0') {
		return 1;
	} else {
		return 0;
	}
}

