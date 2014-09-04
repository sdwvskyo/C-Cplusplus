/*************************************************************************
	> File Name: wuziqi.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  9/ 3 21:01:22 2014
 ************************************************************************/

#include "wuziqi.h"

static void record() 
{
	Node *pNew = (Node *)calloc(1, sizeof(Node));
	pNew->msg.row = msg.row;
	pNew->msg.col = msg.col;
	strcpy(pNew->msg.pre, msg.pre);
	pNew->next = step;
	step = pNew;
}

void initGrid(char *arg)
{
	msg.row = 9;
	msg.col = 9;
	step = NULL;
	if (atoi(arg) == 1) {
		strcpy(msg.chess, BLACK);
	} else {
		strcpy(msg.chess, WHITE);
	}
	strcpy(msg.pre, grid[msg.row][msg.col]);
	strcpy(grid[msg.row][msg.col], CURSOR);
	showGrid();	
}

static int back()
{
	if (step != NULL) {
		strcpy(grid[msg.row][msg.col], msg.pre);
		msg.row = step->msg.row;
		msg.col = step->msg.col;
		strcpy(msg.pre, step->msg.pre);
		strcpy(grid[step->msg.row][step->msg.col], msg.pre);
		Node *p = step;
		step = step->next;
		free(p);
		showGrid();
		return 1;
	} else {
		return 0;
	}
}

static int go()
{
	if (strcmp(msg.pre, BLACK) == 0 || strcmp(msg.pre, WHITE) == 0) {
		return 0;
	}
	record();
	strcpy(grid[msg.row][msg.col], msg.chess);
	strcpy(msg.pre, msg.chess);
	return 1;
}

static void left()
{
	if (msg.col > 0) {
		strcpy(grid[msg.row][msg.col], msg.pre);
		msg.col--;
		strcpy(msg.pre, grid[msg.row][msg.col]);
		strcpy(grid[msg.row][msg.col], CURSOR);
	}
}

static void right()
{
	if (msg.col < 18) {
		strcpy(grid[msg.row][msg.col], msg.pre);
		msg.col++;
		strcpy(msg.pre, grid[msg.row][msg.col]);
		strcpy(grid[msg.row][msg.col], CURSOR);
	}
}

static void up()
{
	if (msg.row > 0) {
		strcpy(grid[msg.row][msg.col], msg.pre);
		msg.row--;
		strcpy(msg.pre, grid[msg.row][msg.col]);
		strcpy(grid[msg.row][msg.col], CURSOR);
	}
}

static void down()
{
	if (msg.row < 18) {
		strcpy(grid[msg.row][msg.col], msg.pre);
		msg.row++;
		strcpy(msg.pre, grid[msg.row][msg.col]);
		strcpy(grid[msg.row][msg.col], CURSOR);
	}
}

void hebing(Msg *recv_msg)
{
	strcpy(grid[recv_msg->row][recv_msg->col], recv_msg->pre);
	if (msg.row == recv_msg->row && msg.col == recv_msg->col) {
		strcpy(msg.pre, recv_msg->pre);
	}
	showGrid();
}

void move()
{
	showGrid();
	printf("your turn\n");
	char ch;
	while (1) {
		ch = getchar();
		if (ch == ' ') {
			if (go()) {
				showGrid() ;
				break;
			}
		} else if (ch == 'b') {
			if (back()) {
				showGrid();
				break;
			}
		}
		switch (ch) {
			case 'w': up(); break;
			case 's': down(); break;
			case 'a': left(); break;
			case 'd': right(); break;
		}
		showGrid();
	}
}

static int heng(Msg msg) {
	int cnt = 0;
	int x, y;
	for (x = msg.row, y = msg.col + 1; y < COL; y++) {
		if (strcmp(msg.chess, grid[x][y]) == 0) {
			cnt++;
		} else {
			break;
		}
	}
	for (x = msg.row, y = msg.col - 1; y > 0; y--) {
		if (strcmp(msg.chess, grid[x][y]) == 0) {
			cnt++;
		} else {
			break;
		}
	}
	return cnt >= 4;
}

static int shu(Msg msg) {
	int cnt = 0;
	int x, y;
	for (x = msg.row + 1, y = msg.col; x < ROW; x++) {
		if (strcmp(msg.chess, grid[x][y]) == 0) {
			cnt++;
		} else {
			break;
		}
	}
	for (x = msg.row - 1, y = msg.col; x > 0; x--) {
		if (strcmp(msg.chess, grid[x][y]) == 0) {
			cnt++;
		} else {
			break;
		}
	}
	return cnt >= 4;
}

static int xie1(Msg msg) {
	int cnt = 0;
	int x, y;
	for (x = msg.row + 1, y = msg.col + 1; x < ROW && y < COL; x++, y++) {
		if (strcmp(msg.chess, grid[x][y]) == 0) {
			cnt++;
		} else {
			break;
		}
	}
	for (x = msg.row - 1, y = msg.col - 1; x > 0 && y > 0; x--, y--) {
		if (strcmp(msg.chess, grid[x][y]) == 0) {
			cnt++;
		} else {
			break;
		}
	}
	return cnt >= 4;
}

static int xie2(Msg msg) {
	int cnt = 0;
	int x, y;
	for (x = msg.row - 1, y = msg.col + 1; x > 0 && y < COL; x--, y++) {
		if (strcmp(msg.chess, grid[x][y]) == 0) {
			cnt++;
		} else {
			break;
		}
	}
	for (x = msg.row + 1, y = msg.col - 1; x < ROW && y > 0; x++, y--) {
		if (strcmp(msg.chess, grid[x][y]) == 0) {
			cnt++;
		} else {
			break;
		}
	}
	return cnt >= 4;
}

int win(Msg recv_msg)
{
	return heng(recv_msg) || shu(recv_msg) || xie1(recv_msg) || xie2(recv_msg);
}

void showGrid()
{
	system("clear");
	int i, j;
	printf(" ");
	for (i = 1; i <= 19; i++) {
		printf ("%2d", i);
	}
	printf("\n");

	for (i = 0; i < 19; i++) {
		printf("%2d", i + 1);
		for (j = 0; j < 18; j++) {
			printf("%s", grid[i][j]);
			printf("─");
		}
		printf("%s\n", grid[i][j]);
	}
	printf("\n");
}
