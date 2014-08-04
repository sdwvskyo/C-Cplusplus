//五子棋游戏

#include <stdio.h>
#include <stdlib.h>

#define N 20

void creatGrid(); //创建棋盘
void printGrid(); //打印棋盘
void left();
void right();
void down();
void up();
void move(); //行动
void update(); //更新屏幕
void go();

char grid[N][N]; //棋盘数组

int main(int argc, char *argv[]) {

	creatGrid();
	printGrid();
	while(1) {
		move();
	}
	getchar();
	return 0;
}

void creatGrid() {
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(j == N - 1) {
				grid[i][j] = '|';
			} else if(i == N - 1) {
				grid[i][j] = '_';
			} else {
				grid[i][j] = ' ';
			}
		}
	}
	grid[0][0] = 1;
}

void printGrid() {
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
}

void go() {
	int i, j;
	for(i = 0; i< N; i++) {
		for (j = 0; j < N; j++) {
			if (grid[i][j] == 1)
				break;
		}
		if(grid[i][j] == 1)
			break;
	}
	grid[i][j] = 'x';
	i++;
	while(grid[++i][j] != ' ')
		;
	grid[i][j] = 1;
}

void move() {
	char ch;
	switch(ch = getchar()) {
		case 'w': up(); break;
		case 'a': left(); break;
		case 's': down(); break;
		case 'd': right(); break;
		case ' ': go(); break;
	}
	update();
}

void update() {
	system("cls");
	printGrid();
}

void left() {
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(grid[i][j] == 1)
				break;
		}
		if(grid[i][j] == 1)
			break;
	}
	grid[i][j] = ' ';
	while(grid[i][--j] != ' ')
		;
	grid[i][j] = 1;
}

void right() {
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(grid[i][j] == 1)
				break;
		}
		if(grid[i][j] == 1)
			break;
	}
	grid[i][j] = ' ';
	while(grid[i][++j] != ' ')
		;
	grid[i][j] = 1;
}

void up() {
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(grid[i][j] == 1)
				break;
		}
		if(grid[i][j] == 1)
			break;
	}
	grid[i][j] = ' ';
	while(grid[++i][j] != ' ')
		;
	grid[i][j] = 1;
}

void down() {
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(grid[i][j] == 1)
				break;
		}
		if(grid[i][j] == 1)
			break;
	}
	grid[i][j] = ' ';
	while(grid[--i][j] != ' ')
		;
	grid[i][j] = 1;
}

