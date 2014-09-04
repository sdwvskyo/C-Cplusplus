/*************************************************************************
	> File Name: topk.h
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 四  9/ 4 20:11:50 2014
 ************************************************************************/

#ifndef _TOPK_H
#define _TOPK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int * initArr(int len);
void showArr(int *arr, int len);
void topk_heap(int *ar, int len, int k);
void heapSort(int *ar, int len);
void topk_quick(int *ar, int low, int high, int k);

#endif
