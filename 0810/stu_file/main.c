#include "stu_file.h"

int main(int arfc, char *argv[])
{
	LinkList L;
	char file[NAME_SIZE];
	printf("Input the file name:\n");
	scanf("%s", file);

	initStu(file, &L);
	printStu(L);

	return 0;
}
