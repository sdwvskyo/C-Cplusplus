#ifndef _HOLY_BIBLE_H
#define _HOLY_BIBLE_H
#define LEN 50

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	char word[LEN];
	int count;
	struct node *next;
} Node, *pNode;

void sortByFreq(pNode *L);

void sortByWordOder(char *filename, pNode *L);

void printLinkList(pNode L, int size);

#endif
