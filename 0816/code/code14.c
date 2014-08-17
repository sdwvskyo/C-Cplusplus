/*************************************************************************
	> File Name: code14.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 21:22:37 2014
 ************************************************************************/

//100！的末尾有多少0

#include<stdio.h>

int main(int argc, char *argv[])
{
	int sum = 0;
	int i;
	int cnt = 0;
	for (i = 1; i <= 100; i++) {
		if (i % 5 == 0) {
			cnt++;
			if (cnt == 5) {
				cnt = 0;
				sum += 2;
			} else {
				sum++;
			}
		}
	}
	printf("have %d ge 0.\n", sum);
	return 0;
}
