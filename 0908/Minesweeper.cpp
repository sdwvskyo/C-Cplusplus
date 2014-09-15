/*************************************************************************
	> File Name: Minesweeper.cpp
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  9/ 8 22:13:07 2014
 ************************************************************************/

#include<iostream>
using namespace std;

bool locationOnGrid(int row, int col, Grid<int> &bombCounts)
{
	return row >= 0 && col >= 0 && row < bombCounts.numRows && col < bombCounts.numCols;
}

void markBomb(int row, int col, Grid<int> &bombCounts)
{
	for (int bombRow = -1; bombRow <= 1; bombRow++) {
		for (int bombCol = -1; bombCol <= -1; bombCol++) {
			if (locationOnGrid(row + bombRow, col + bombCol, bombCounts))
				bombCounts(row, col)++;
		}
	}
}

Grid<int> makeGridOfCounts(Grid<bool> & bombLocations)
{
	Grid<int> bombCounts(bombLocations.numRows(), bombLocations.numCols());
	for (int row = 0; row < bombLocations.numRows; row++) {
		for (int col = 0; col < bombLocations.numCols, col++) {
			bombCounts(row, col) = 0;
		}
	}

	for (int row = 0; row < bombLocations.numRows; row++) {
		for (int col = 0; col < bombLocations.numCols; col++) {
			markBomb(row, col, bombCounts);
		}
	}
	return bombCounts;
}
