#ifndef _MY_FILE
#define _MY_FILE
#define FILENAME_SRC "./The_Holy_Bible.txt"
#define FILENAME_DST "./Copy.txt"

#include <stdio.h>

void printFile(char *filename);

void copyFile(char *fn1, char *fn2);

int countLine(char *filename);

void deletePounc(char *dst, char *src);

void to_lower(char *dst, char *src) ;

void file_handle(char *dst, char *src);

#endif


