/*************************************************************************
	> File Name: maze.h
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  9/ 9 23:43:36 2014
 ************************************************************************/
#ifndef _MAZE_H
#define _MAZE_H

#include<stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

typedef struct pos {
	int x;
	int y;
} Pos;

typedef struct stack {
	Pos pos;
	struct stack *next;
} Node;

int isOk(int **maze, int row, int col, Pos pos, Pos next);
int choosePos(Pos cur, Pos pre);
void push(Node **head, Pos pos);
Pos pop(Node **head);
void showStack(Node *stack);
void initNext(Pos next[4]);
int ** initMaze(int row, int col);
void showMaze(int **maze, int row, int col);

#endif
