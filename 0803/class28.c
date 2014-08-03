/*
【程序 28】 五个人问岁数。
题目:有 5 个人坐在一起,问第五个人多少岁?他说比第 4 个人大 2 岁。问第 4 个人岁数,他说比第 3 个人大 2 岁。问第三个人,又说比第 2 人大两岁。问第 2 个人,说比第一个人大两岁。最后 问第一个人,他说是 10 岁。请问第五个人多大?
*/

#include <stdio.h>
int age(int n) {
	if(n == 1)
		return 10;
	else 
		return age(n - 1) + 2;
}


int main(int argc, char *argv[]) {
	
	printf("The 5th people's age is: %d\n", age(5));	
	return 0;
}
