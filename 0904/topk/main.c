/*************************************************************************
	> File Name: main.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  9/ 4 21:16:37 2014
 ************************************************************************/

#include "topk.h"

int main(int argc, char *argv[])
{
	srand(getpid());
	if (argc < 3) {
		printf("argument less\n");
		exit(EXIT_FAILURE);
	}
	int len = atoi(argv[1]);
	int k = atoi(argv[2]);
	int *ar = initArr(len);
	showArr(ar, len);
	topk_quick(ar, 0, len - 1, k);
	showArr(ar, k);
	topk_heap(ar, len, k);
	showArr(ar, k);
	heapSort(ar, len);
	showArr(ar, len);
	return 0;
}

