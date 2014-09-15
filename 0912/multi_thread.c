/*************************************************************************
	> File Name: /Users/sdw/sdw/wangdao/C/0912/multi_thread.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  9/12 10:29:13 2014
 ************************************************************************/

#include "multi_thread.h"

static int addWork(Crew *crew, char *path, char *filename, char *string)
{
	Work *task = (Work *)calloc(1, sizeof(Work));
	if (task == NULL) {
		perror("calloc task");
		exit(EXIT_FAILURE);
	}
	strcpy(task->path, path);
	if (filename != NULL) {
		strcat(task->path, "/");
		strcat(task->path, filename);
	}
	task->string = string;
	task->next = NULL;
	if (crew->first == NULL) {
		crew->first = task;
		crew->last = task;
	} else {
		crew->last->next = task;
		crew->last = task;
	}
	crew->work_count++;
    return 0;
}

static int getWork(Crew *crew, Work **work)
{
	int status;
	status = pthread_mutex_lock(&crew->mutex);
	if (status != 0) {
		perror("mutex lock");
		return status;
	}
	while (crew->first == NULL) {
		status = pthread_cond_wait(&crew->go, &crew->mutex);
		if (status != 0) {
			perror("cond wait go");
			return status;
		}
	}
	*work = crew->first;
	crew->first = crew->first->next;
	if (crew->first == NULL) 
		crew->last = NULL;
	status = pthread_mutex_unlock(&crew->mutex);
	if (status != 0) {
		perror("thread mutex unlock");
		return status;
	}
	return 0;
}

static void findStr(Work *work) 
{
	FILE *fp = fopen(work->path, "r");
	if (fp == NULL) {
		printf("can not open %s\n", work->path);
		return;
	}
	char buf[N];
	while (memset(buf, 0, N), fgets(buf, N, fp) != NULL) {
		if (strstr(buf, work->string)) {
			printf("%s", work->path);
			break;
		}
	}
	fclose(fp);
}

static void doWork(Crew *crew, Work *work)
{
	int status;
	struct stat filestat;
	struct dirent *dirbuf;
	status = lstat(work->path, &filestat);
	if (status != 0)
		return;

	if (S_ISDIR(filestat.st_mode)) {
		DIR *pDir = opendir(work->path);
		if (pDir == NULL) {
			return;	
		}
		while ((dirbuf = readdir(pDir)) != NULL) {
			if (strcmp(dirbuf->d_name, ".") == 0 || strcmp(dirbuf->d_name, "..") == 0) {
				continue;
			}
			status = pthread_mutex_lock(&crew->mutex);
			if (status != 0) 
				return;
			addWork(crew, work->path, dirbuf->d_name, work->string);
			status = pthread_cond_signal(&crew->go);
			if (status != 0)
				return;
			status = pthread_mutex_unlock(&crew->mutex);
			if (status != 0) 
				return;
		}
	} else if (S_ISREG(filestat.st_mode)) {
		findStr(work);
	}
}

void *work_routine(void *arg)
{
	Worker *mine = (Worker *)arg;
	Crew *crew = mine->crew;
	int status;

	status = pthread_mutex_lock(&crew->mutex);
	if (status != 0) {
		perror("mutex lock");
		exit(EXIT_FAILURE);
	}
	while (crew->work_count == 0) {
		status = pthread_cond_wait(&crew->go, &crew->mutex);
		if (status != 0) {
			perror("cond wait go");
			exit(EXIT_FAILURE);
		}
	}
	status = pthread_mutex_unlock(&crew->mutex);
	if (status != 0) {
		perror("thread mutex unlock");
		exit(EXIT_FAILURE);
	}

	Work *work;
	while (1) {

		status = getWork(crew, &work);
		if (status != 0) {
			perror("getWork");
			exit(EXIT_FAILURE);
		}

		doWork(crew, work);

		status = pthread_mutex_lock(&crew->mutex);
		if (status != 0) {
			perror("mutex lock");
			exit(EXIT_FAILURE);
		}
		while (crew->work_count <= 0) {
			status = pthread_cond_broadcast(&crew->done);
			if (status != 0) {
				perror("pthread_cond_broadcast done");
				exit(EXIT_FAILURE);
			}
		}
		status = pthread_mutex_unlock(&crew->mutex);
		if (status != 0) {
			perror("unlock mutex");
			exit(EXIT_FAILURE);
		}
	}
	return NULL;
}

int startCrew(Crew *crew, char *path, char *string)
{
	int status = 0;
	status = pthread_mutex_lock(&crew->mutex);
	if (status != 0)
		return status;

	while (crew->work_count > 0) {
		status = pthread_cond_wait(&crew->done, &crew->mutex);
		if (status != 0) {
			pthread_mutex_unlock(&crew->mutex);
			return status;
		}
	}
	
	addWork(crew, path, NULL, string);
	
	status = pthread_cond_signal(&crew->go);
	if (status != 0) {
		crew->first = NULL;
		crew->last = NULL;
		crew->work_count--;
		pthread_mutex_unlock(&crew->mutex);
		return status;
	}

	while (crew->work_count > 0) {
		status = pthread_cond_wait(&crew->done, &crew->mutex);
		if (status != 0) {
			perror("pthread_cond_wait done");
			exit(EXIT_FAILURE);
		}
	}

	status = pthread_mutex_unlock(&crew->mutex);
	if (status != 0) {
		perror("unlock crew mutex");
		exit(EXIT_FAILURE);
	}
    return 0;
}

int initCrew(Crew *crew)
{
	int status;
	crew->work_count = 0;
	crew->first = NULL;
	crew->last = NULL;
	status = pthread_mutex_init(&crew->mutex, NULL);
	if (status != 0)
		return status;
	pthread_cond_init(&crew->done, NULL);
	if (status != 0)
		return status;
	pthread_cond_init(&crew->go, NULL);
	if (status != 0)
		return status;

	for (int i = 0; i < CREW_SIZE; i++) {
		crew->crew[i].crew = crew;
		status = pthread_create(&crew->crew[i].thread, NULL, work_routine, (void *)&crew->crew[i]);
		if (status != 0) {
			perror("create worker thread");
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}

