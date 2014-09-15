/*************************************************************************
	> File Name: express.h
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  9/10 19:24:51 2014
 ************************************************************************/

#ifndef _EXPRESS_H
#define _EXPRESS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

typedef struct digit {
	int dig[N];
	int top;
} Digit;

typedef struct opretor {
	char op[N];
	int top;
} OpStack;

int pre(char op);
int isOperator(char ch);
void pushDigit(Digit *digit, int num);
int popDigit(Digit *digit);
void pushOpStack(OpStack *opStack, char ch);
char popOpStack(OpStack *opStack);
int isEmpty(OpStack opStack);
char top(OpStack opStack);
void comput(Digit *digit, OpStack *opStack);
int isEmptyDigit(Digit digitStack);

#endif
