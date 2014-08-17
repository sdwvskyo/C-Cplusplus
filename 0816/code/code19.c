/*************************************************************************
	> File Name: code19.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 六  8/16 16:06:27 2014
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *rgv[])
{
	srand(time(NULL));
	int ar[20];
	int i;
	for (i = 0; i < 20; i++) {
		if (rand() % 2 == 0) {
			ar[i] = rand() % 100;
		} else {
			ar[i] = -rand() % 100;
		}
		printf("%4d", ar[i]);
	}
	printf("\n");
	int start = 0;
	int end = 20 - 1;

	while (start < end) {
		while (ar[start] < 0) {
			start++;
		}
		while(ar[end] > 0) {
			end--;
		}
		int tmp = ar[start];
		ar[start] = ar[end];
		ar[end] = tmp;
	}

	for (i = 0; i < 20; i++) {
		printf("%4d", ar[i]);
	}
	printf("\n");

	return 0;
}
