/*
程序 20】小球自由下落。
题目:一球从 100 米高度自由落下,每次落地后反跳回原高度的一半;再落下,求它在 第 10 次落地时,共经过多少米?第 10 次反弹多高?
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	double height = 100.0;
	double half = height * 0.5;
	for (int i = 2; i <= 10; i++) {
		height += 2 * half;
		half /= 2;
		printf("di %dth luodi de lujing : %f\n", i, height);
	}

	return 0;
}
