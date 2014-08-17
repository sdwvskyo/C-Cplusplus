#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	time_t ttime;
	struct tm *local_tm;
	FILE *fp = fopen("log.txt", "a+");
	if (fp == NULL) {
		perror("Open file error.\n");
			exit(1);
	}
	char line[1024];
	int cnt = 1;
	while (fgets(line, 1024, fp) != NULL) {
		cnt++;
	}
	fseek(fp, 0, SEEK_END);
	while (1) {
		time(&ttime);
		local_tm = localtime(&ttime);
		fprintf(fp, "%d %d-%d-%d %d:%d:%d\n", cnt++, local_tm->tm_year + 1900, local_tm->tm_mon,
				local_tm->tm_mday, local_tm->tm_hour, local_tm->tm_min, local_tm->tm_sec);
		fflush(fp);
		sleep(1);
	}
	fclose(fp);

	return 0;
}
