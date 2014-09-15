/*************************************************************************
	> File Name: multi_thread.h
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  9/12 09:16:00 2014
*************************************************************************/

#ifndef _THREAD_FIND
#define _THREAD_FIND

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pthread.h>
#include <pthread.h>

#define N 1024
#define CREW_SIZE 4

//Task list
typedef struct work {
	char path[N];
	char *string;
	struct work *next;
} Work;

//thread list
typedef struct worker {
	pthread_t thread;
	struct crew *crew;
} Worker;

//work crew info
typedef struct crew {
	Worker crew[CREW_SIZE];
	int work_count;
	Work *first, *last;
	pthread_mutex_t mutex;
	pthread_cond_t done;
	pthread_cond_t go;
} Crew;

int initCrew(Crew *crew);
int startCrew(Crew *crew, char *path, char *string);

#endif
