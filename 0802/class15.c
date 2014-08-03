/*
【程序 15】利用条件运算符的嵌套完成学习成绩的转换。 题目:利用条件运算符的嵌套来完成此题:学习成绩>=90 分的同学用 A 表示,60-89 分之间的用 B 表示, 60 分以下的用 C 表示。
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	int score;
	char grade;
	printf("Please enter a score:\n");
	scanf("%d", &score);
	grade = score >= 90 ? 'A' : (score >= 60 ? 'B' : 'C');

	printf("\nYour score %d is grade: %c\n", score, grade);

	return 0;
}
