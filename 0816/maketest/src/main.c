/*************************************************************************
	> File Name: src/main.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 17:12:27 2014
 ************************************************************************/

#include "func.h"
int main(int argc, char *argv[])
{
	double a, b;
	char ch;
	while(scanf("%lf%c%lf", &a, &ch, &b) == 3) {
		switch(ch) {
			case '+':
				printf("%.2lf + %.2lf = %.2lf\n", a, b, add(a, b));
				break;
			case '-':
				printf("%.2lf - %.2lf = %.2lf\n", a, b, sub(a, b));
				break;
			case '*':
				printf("%.2lf * %.2lf = %.2lf\n", a, b, mul(a, b));
				break;
			case '/':
				printf("%.2lf / %.2lf = %.2lf\n", a, b, div(a, b));
				break;
		}
	}
	return 0;
}

