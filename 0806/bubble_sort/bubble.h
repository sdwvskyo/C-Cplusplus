#ifndef _BUBBLE_H
#define _BUBBLE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int swapCnt;
int cmpCnt;

void bubble1(int ar[], int n); //单向冒泡
void bubble2(int ar[], int n); //双向冒泡 
void creat(int ar[], int n); //创建数组
void print(int ar[], int n); //打印数组
void swap(int *a, int *b);

#endif
