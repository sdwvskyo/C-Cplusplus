#include "student.h"

#define N 20

int main(int argc, char *argv[]) 
{
	srand(time(NULL));
	Student student[N];
	int i;
	float aver[SCORE_NUM];
	for (i = 0; i < 3; i++) {
		init_student(&student[i]);
	}

	for (i = 0; i < 3; i++) {
		print(&student[i]);
	}

	average_score(student, aver, 3);


	return 0;
}
