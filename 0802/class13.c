/*
【程序 13】打印出所有的“水仙花数”。 题目:打印出所有的“水仙花数”,所谓“水仙花数”是指一个三位数,其各位数字立方和等于该数 本身。例如:153 是一个“水仙花数”,因为 153=1 的三次方+5 的三次方+3 的三次方。
*/

#include <stdio.h>

int fun(int n);

int main(int argc, char *argv[]) {
	for (int i = 100; i < 1000; i++)
		if (fun(i))
			printf("%d\t", i);
	printf("\n");
	return 0;
}

int fun(int n) {
	int i = n / 100;
	int j = n / 10 % 10;
	int k = n % 10;
	if(n == i * i * i + j * j *j + k * k * k)
		return 1;
	else
		return 0;
}
