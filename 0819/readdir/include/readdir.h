/*************************************************************************
	> File Name: include/readdir.h
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/19 15:37:34 2014
 ************************************************************************/
#ifndef _READDIR_H
#define _READDIR_H

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <uuid/uuid.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#define N 1024

void printInfo(char *name);

void modeToStr(mode_t mode, char *dest);

void timeWithoutSec(time_t src_time, char *dst_time);

int cmp(const void *a, const void *b);

#endif
