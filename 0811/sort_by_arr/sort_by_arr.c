include "sort_by_array.h"

void initArray(char *filename, Word *wordArr)
{
	FILE *fp = fopen("filename", "r");
	if (fp == NULL) {
		perror("Open file error.\n");
		return;
	}
	int index = 0;
	char str[LEN];
	while (memset(str, 0, LEN), fscanf(fp, "%s", str) == 1) {
		while 
		wordArr = (Word *)realloc(wordArr, (sizeof(Word) * (++index)));

	}
}

