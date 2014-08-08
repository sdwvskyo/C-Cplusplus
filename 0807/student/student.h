#ifndef _STUDENT_H
#define _STUDENT_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCORE_NUM 5

struct student 
{
	char name[40];
	unsigned int id;
	float score[SCORE_NUM];
	float aver_score;
	float sum_score;
};

typedef struct student Student;

void init_student(Student *sdt);

int add_score(const Student *sdt);

void average_score(Student *sdt, float *ar, int n);

void print(const Student *sdt);
#endif
