//测试随机数

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int cnt = 0;
	int key;
	while((key = rand() % 100)) {
		printf("%4d", key);
		cnt++;
	}

	printf("\n0之前随机了%d个数字\n", cnt);
	return 0;
}
