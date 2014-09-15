/*************************************************************************
	> File Name: main.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  9/10 19:38:39 2014
 ************************************************************************/

#include "express.h"

int main(int argc, char *argv[])
{
	Digit digitStack;
	OpStack opStack;
	memset(&digitStack, 0, sizeof(Digit));
	memset(&opStack, 0, sizeof(OpStack));
	char express[N];
	while (memset(express, 0, N), fgets(express, N, stdin) != NULL) { 
		char *last = NULL;
		char *fast = express;
		int digit;
		while (*fast != '\0') {
			if (isdigit(*fast)) {
				sscanf(fast, "%d", &digit);
				pushDigit(&digitStack, digit);
				printf("push %d in stack\n", digit);
				while (*fast != '\0' && isdigit(*fast))
					fast++;
				last = fast - 1;
			} else if (isOperator(*fast)) {
				if (*fast == '-') {
					if (last == NULL || *last == '(') {
						sscanf(fast, "%d", &digit);
						pushDigit(&digitStack, digit);
						printf("push %d in stack\n", digit);
						fast++;
						while (isdigit(*fast))
							fast++;
						last = fast - 1;		
					} else {
						if (isEmpty(opStack) || (pre(top(opStack)) < pre(*fast))) {
							pushOpStack(&opStack, *fast);
							printf("push %c in stack\n", *fast);
						} else {
							while (top(opStack) != '(' && !isEmpty(opStack) && pre(*fast) <= pre(top(opStack))) {
								comput(&digitStack, &opStack);
							}
							pushOpStack(&opStack, *fast);
							printf("push %c in stack\n", *fast);
						}
						last = fast++;
					}
				} else if (*fast == '(') {
					pushOpStack(&opStack, *fast);
					printf("push %c in stack\n", *fast);
					last = fast++;
				} else if (*fast == ')') {
					while (top(opStack) != '(') {
						comput(&digitStack, &opStack);
					}
					popOpStack(&opStack);
					printf("pop %c out stack\n", *fast);
					last = fast++;
				} else {
					if (isEmpty(opStack) || pre(top(opStack)) < pre(*fast)) {
						pushOpStack(&opStack, *fast);
						printf("push %c in stack\n", *fast);
					} else {
						while (top(opStack) != '(' && !isEmpty(opStack) && pre(*fast) <= pre(top(opStack))) {
							comput(&digitStack, &opStack);
						}
						pushOpStack(&opStack, *fast);
						printf("push %c in stack\n", *fast);
					}
					last = fast++;
				}
			} else {
				fast++;
			}
		}
		while (!isEmpty(opStack)) {
			comput(&digitStack, &opStack);
		}
		while (!isEmptyDigit(digitStack)) {
			printf("digit: %d\n", popDigit(&digitStack));
		}
		printf("Done!\n");
	}
	return 0;
}
