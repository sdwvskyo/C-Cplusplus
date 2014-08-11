#ifndef _STU_FILE
#define _STU_FILE
#define NAME_SIZE 50
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stu {
	int id;
	char name[NAME_SIZE];
	float score;
	struct stu *next;
} Node, *LinkList;


void initStu(char *filename, LinkList *L);

void printStu(LinkList L);

#endif
