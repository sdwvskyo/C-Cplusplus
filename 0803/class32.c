/*
【程序 32】Press any key to change color。
题目:Press any key to change color, do you want to try it. Please hurry up!
*/

#include <stdio.h>

int main(int argc, char *argv[]) {

	int color;
	for (color = 0; color < 8; color++) {
		textbackground(color);
		printf("This is color %d\r\n", color);
		printf("Press any key to continue.\n");
		getchar();
	}
	return 0;
}
