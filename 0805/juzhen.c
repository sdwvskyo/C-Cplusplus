//将数字排列成矩形

#include <stdio.h>
#define MAX 100

void shexing(int row, int col);//蛇形矩阵
void luoxuan(int row, int col); //正螺旋
void fanluoxuan(int row, int col); //反螺旋
void print(int row, int col); //打印矩阵

int ar[MAX][MAX];

int main(int argc, char *argv[]) {
	int row, col;
	while (fflush(stdin), scanf("%d%d", &row, &col) == 2) {

		shexing(row, col);
		luoxuan(row, col);
		fanluoxuan(row, col);

	}
	return 0;
}

void shexing(int row, int col) {
	int i, j;
	int num = 1;
	for (i = 0; i < row; i++) {
		if (i % 2 == 0) {			
			for (j = 0; j < col; j++) {
				ar[i][j] = num++;
			}
		} else {
			for (j = col - 1; j >= 0; j--) {
				ar[i][j] = num++;
			}
		}
	}
	print(row, col);
}

void luoxuan(int row, int col) {
	int i, j;
	int tmp = row < col ? row : col;
	int sum = 1;
	for(i = 0; i < (tmp + 1) / 2; i++) {
		for( j = i; j < col - i; j++) {
			if(sum > row * col)
				break;
			ar[i][j] = sum++;
		}
		for(j = i + 1; j < row - i - 1; j++) {
			if(sum > row * col)
				break;
			ar[j][col - i - 1] = sum++;
		}
		for(j =  col - i - 1; j > i; j--) {
			if(sum > row * col)
				break;
			ar[row - i - 1][j] = sum++;
		}
		for(j = row - i -1; j > i; j--) {
			if(sum > row * col)
				break;
			ar[j][i] = sum++;
		}
	}
	print(row, col);
}

void fanluoxuan(int row, int col) {
	int i, j;
	int tmp = row < col ? row : col;
	int sum = row * col;
	for(i = 0; i < (tmp + 1) / 2; i++) {
		for( j = col - i - 1; j >= i; j--) {
			if(sum < 1)
				break;
			ar[i][j] = sum--;
		}
		for(j = i + 1; j < row - i - 1; j++) {
			if(sum < 1)
				break;
			ar[j][i] = sum--;
		}
		for(j = i; j < col - i - 1; j++) {
			if(sum < 1)
				break;
			ar[row - i - 1][j] = sum--;
		}
		for(j = row - i -1; j > i; j--) {
			if(sum < 1)
				break;
			ar[j][col - i -1] = sum--;
		}
	}
	print(row, col);
}

void print(int row, int col) {
	int i, j;
	printf("\n");
	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			printf("%3d", ar[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
