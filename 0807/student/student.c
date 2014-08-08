#include "student.h"

void init_student(Student *sdt)
{
	char ch;
	puts("Input the name of student: ");
	while (fflush(stdin), scanf("%s", sdt->name) != 1) {
		puts("name input error, input again!");
		while((ch = getchar()) != '\n')
			continue;
	}
	puts("Input the ID of the student: ");
	while (fflush(stdin), scanf("%u", &sdt->id) != 1) {
		puts("ID input error!");
		while((ch = getchar()) != '\n')
			continue;
	}
	puts("Init score by random numbers.");
	for (int i = 0; i < SCORE_NUM; i++) {
		sdt->score[i] = rand() % 101;
	}
	sdt->sum_score = add_score(sdt);
	sdt->aver_score = add_score(sdt) / SCORE_NUM;
}

int add_score(const Student *sdt)
{
	int sum = 0;
	for (int i = 0; i < SCORE_NUM; i++) {
		sum += sdt->score[i];
	}
	return sum;
}

void average_score(Student *sdt, float *ar, int n)
{

	for (int i = 0; i < SCORE_NUM; i++) {
		for(int j = 0; j < n; j++) {
			ar[i] += sdt[j].score[i];	
		}
		ar[i] /= n;
		printf("averScore-%d: %.2f\t", i + 1, ar[i]);
	}
	printf("\n");
}

void print(const Student *sdt) 
{
	printf("ID: %06d\t", sdt->id);
	printf("Name: %s\t", sdt->name);
	for (int i = 0; i < SCORE_NUM; i++) {
		printf("Score-%d: %.2f\t", i + 1, sdt->score[i]);
	}
	printf("Sum: %.2f\t", sdt->sum_score);
	printf("Average: %.2f\n", sdt->aver_score);
}

