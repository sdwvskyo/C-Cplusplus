/*************************************************************************
	> File Name: maze.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  9/ 9 23:56:05 2014
 ************************************************************************/

#include "maze.h"

int isOk(int **maze, int row, int col, Pos pos, Pos next)
{
	pos.x += next.x;
	pos.y += next.y;
	return pos.x >= 0 && pos.y >= 0 && pos.x < row && pos.y < col && maze[pos.x][pos.y] == 0;
}

int choosePos(Pos cur, Pos pre)
{
	int op;
	int x = pre.x - cur.x;
	int y = pre.y - cur.y;
	if (x == 0 && y == 1)
		op = 1;
	else if (x == 1 && y == 0)
		op = 2;
	else if (x == 0 && y == -1)
		op = 3;
	else if (x == -1 && y == 0)
		op = 4;
	return op;
}

void push(Node **head, Pos pos)
{
	Node *newNode = (Node *)calloc(1, sizeof(Node));
	newNode->pos = pos;
	newNode->next = *head;
	*head = newNode;
}

Pos pop(Node **head)
{
	Pos tmp = (*head)->pos;
	Node *p = *head;
	*head = (*head)->next;
	free(p);
	return tmp;
}

void showStack(Node *stack)
{
	if (stack == NULL)
		return;
	else {
		showStack(stack->next);
		printf("x: %d, y: %d\n", stack->pos.x, stack->pos.y);
	}
}

void initNext(Pos next[4])
{
	next[0].x = 0;
	next[0].y = 1;

	next[1].x = 1;
	next[1].y = 0;

	next[2].x = 0;
	next[2].y = -1;

	next[3].x = -1;
	next[3].y = 0;
}

int ** initMaze(int row, int col)
{
	int **maze = (int **)calloc(row, sizeof(int *));
	for (int i = 0; i < row; i++) {
		*(maze + i) = calloc(col, sizeof(int));
		for (int j = 0; j < col; j++) {
			if (rand() % 2 == 1) {
				maze[i][j] = 1;
			}
		}
	}
	maze[0][0] = 0;
	maze[row-1][col-1] = 0;
	return maze;
}

void showMaze(int **maze, int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

