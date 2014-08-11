#ifndef _SORT_BY_ARR_H
#define _SORT_BY_ARR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LEN 40
typedef struct word {
	char word[LEN];
	int count;
} Word;

void initArray(char *filename, Word *wordArr);

#endif
