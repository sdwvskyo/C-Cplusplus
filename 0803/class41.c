/*
【程序 41】题目:学习 static 定义静态变量的用法
*/

#include <stdio.h>
void fun() {
	int var = 0;
	static int static_var = 0;
	printf("var = %d\n", var);
	printf("static_var = %d\n", static_var);
	var++;
	static_var++;
}

int main(int argc, char *argv[]) {

	for (int i = 0; i <= 3; i++)
		fun();	

	return 0;
}
