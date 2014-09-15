/*************************************************************************
	> File Name: main1.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  9/10 23:28:04 2014
 ************************************************************************/

#include "maze.h"

int main(int argc, char *argv[])
{
	assert(3 == argc);
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);
	srand(time(NULL));

	int **maze = initMaze(row, col);
	showMaze(maze, row, col);

	Node *stack = NULL;
	Pos cur;
	cur.x = 0;
	cur.y = 0;
	push(&stack, cur);
	maze[cur.x][cur.y] = 2;
	while (cur.x != row - 1 || cur.y != col - 1) {
		printf("x: %d, y: %d\n", cur.x, cur.y);
		while (op <= 3) {
			if (isOk(maze, row, col, cur, next[op])) {
				cur.x += next[op].x;
				cur.y += next[op].y;
				maze[cur.x][cur.y] = 2;
				op = 0;
				push(&stack, cur);
				break;
			} else {
				op++;
			}
		}
		if (op > 3) {
			if (stack == NULL) {
				showMaze(maze, row, col);
				printf("No path!\n");
				exit(1);
			} else {
				Pos pre = cur;
				cur = pop(&stack);
				op = choosePos(cur, pre);
			}
		}
	}
	printf("Find a path!\n");
	showMaze(maze, row, col);
	showStack(stack);
	return 0;
}


