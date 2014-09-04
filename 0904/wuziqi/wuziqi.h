/*************************************************************************
	> File Name: wuziqi.h
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  9/ 3 21:01:14 2014
 ************************************************************************/

#ifndef _WUZIQI_H
#define _WUZIQI_H

#include <pthread.h>
#include <my_socket.h>

#define IP "192.168.0.114"
#define PORT 8888
#define BLACK "●"
#define WHITE "○"
#define CURSOR "■"

#define ROW 19
#define COL 19

extern char grid[ROW][COL][4];

typedef struct msg {
	int row;
	int col;
	char chess[4];
	char pre[4];
} Msg;

typedef struct list {
	Msg msg;
	struct list *next;
} Node;

Msg msg;
Node *step;

void initGrid(char *arg);
void hebing(Msg *recv_msg);
void move();
int win(Msg recv_msg);
void showGrid();

#endif
