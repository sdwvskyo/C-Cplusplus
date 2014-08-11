#include "my_file.h"

void printFile(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("error");
    }
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
}

void copyFile(char *dst, char *src)
{
    FILE *fp_src = fopen(src, "r");
    FILE *fp_dst = fopen(dst, "w");
    if(fp_src == NULL || fp_dst == NULL) {
        perror("error");
    }
    int ch;
    while ((ch = fgetc(fp_src)) != EOF) {
        fputc(ch, fp_dst);
    }
    printf("Copy is complete!\n");
    fclose(fp_dst);
    fclose(fp_src);
}

int countLine(char *filename)
{
	int cnt = 1;
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("error");
	}
	int ch;
	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n')
			cnt++;
	}
	printf("Line = %d.\n", cnt);
	fclose(fp);
	return cnt;
}

static int my_ispounc(char ch)
{
	if ((ch == ' ') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '\n') || ((ch >= '0') && (ch <= '9'))) {
		return 0;
	} else {
		return 1;
	}
}

void deletePounc(char *dst, char *src) 
{
	int ch;
	FILE *fp_dst = fopen(dst, "w");
	FILE *fp_src = fopen(src, "r");
	while ((ch = fgetc(fp_src)) != EOF) {
		if (!my_ispounc(ch)) {
			fputc(ch, fp_dst);
		}
	}
	fclose(fp_dst);
	fclose(fp_src);
}

void to_lower(char *dst, char *src) 
{
	FILE *fp_src = fopen(src, "r");
	FILE *fp_dst = fopen(dst, "w");
	int ch;
	while ((ch = fgetc(fp_src)) != EOF) {
		if ((ch >= 'A') && (ch <= 'Z')) {
				ch += 32;
		}
		fputc(ch, fp_dst);
	}
	fclose(fp_src);
	fclose(fp_dst);
}


void file_handle(char *dst, char *src) 
{
	FILE *fp_src = fopen(src, "r");
	FILE *fp_dst = fopen(dst, "w");
	int ch;
	while ((ch = fgetc(fp_src)) != EOF) {
		if ((ch >= 'A') && (ch <= 'Z')) {
			ch += 32;
			fputc(ch, fp_dst);
		} else if (my_ispounc(ch)) {
			fputc(' ', fp_dst);
		} else {
			fputc(ch, fp_dst);
		}
	}
	fclose(fp_dst);
	fclose(fp_src);
}

