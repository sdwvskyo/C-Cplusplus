/*************************************************************************
	> File Name: modeToStr.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  8/19 16:21:48 2014
 ************************************************************************/

#include "readdir.h"

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
	} 
	if (S_ISLNK(mode)) {
		dest[0] = 'l';
	} 
}

