/*************************************************************************
	> File Name: /Users/sdw/sdw/wangdao/C/0910/express.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  9/10 19:48:51 2014
 ************************************************************************/

#include "express.h"

void comput(Digit *digit, OpStack *opStack)
{
	int b = popDigit(digit);
	int a = popDigit(digit);
	char ch = popOpStack(opStack);
	int result = 0;
	switch (ch) {
		case '+': 
			result = a + b; 
			break;
		case '-':
			result = a - b; 
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			if(b != 0) {
				result = a / b;
			} else {
				printf("diviver can not be 0!\n");
				return;
			}
			break;
	}
	pushDigit(digit, result);
	printf("push result : %d in stack\n", result);
}

int isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%' || ch == '(' || ch == ')';
}

int pre(char op)
{
	if (op == '+' || op == '-')
		return 0;
	else if (op == '*' || op == '/' || op == '%')
		return 1;
	else
		return -1;
}

void pushDigit(Digit *digit, int num)
{
	if (digit->top >= N) {
		printf("stack is full!\n");
		return;
	}
	digit->dig[(digit->top)++] = num;
}

int popDigit(Digit *digit)
{
	if (top <= 0) {
		printf("stack is empty!\n");
		exit(1);
	}
	return digit->dig[--(digit->top)];
}

void pushOpStack(OpStack *opStack, char ch)
{
	if (opStack->top >= N) {
		printf("stack is full!\n");
		return;
	}
	opStack->op[(opStack->top)++] = ch;
}

char popOpStack(OpStack *opStack)
{
	if (opStack->top <= 0) {
		printf("stack is empty!\n");
		exit(1);
	}
	return opStack->op[--(opStack->top)];
}

char top(OpStack opStack)
{
	return opStack.op[--(opStack.top)];
}

int isEmpty(OpStack opStack)
{
	return opStack.top <= 0;
}

int isEmptyDigit(Digit digitStack)
{
	return digitStack.top <= 0;
}
