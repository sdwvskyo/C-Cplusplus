#include "stu_score.h"

static void replace_comma(char *str) 
{
	while (*str != '\0') {
		if (*str == ',') {
			*str = ' ';
		}
		str++;
	}
}
//求出每个学生成绩的平均值
void average(char *dst, char *src)
{
	FILE *fp_src = fopen(src, "r");
	FILE *fp_dst = fopen(dst, "w");
	if (fp_dst == NULL || fp_src == NULL) {
		perror("open file error\n");
	}
	int	ar[6];
	char line[N];
	int aver_cnt = 0;
	while (memset(line, 0, N), fgets(line, N, fp_src) != NULL) {
		replace_comma(line);
		memset(ar, 0, 6);
		if ((aver_cnt = sscanf(line, "%d%d%d%d%d%d", 
					&ar[0], &ar[1], &ar[2], &ar[3], &ar[4], &ar[5])) > 1) {
			float aver = 0.0;
			float sum = 0.0;
			for (int i = 1; i < aver_cnt; i++) {
				sum += ar[i];	
			}
			aver = sum / (aver_cnt - 1);
			fprintf(fp_dst, "%d,%d,%.1f,%.1f\n", ar[0], aver_cnt - 1, sum, aver);
		} else {
			fprintf(fp_dst, "Load data error!\n");
		}
	}
	printf("Done!\n");
	fclose(fp_dst);
	fclose(fp_src);
}



