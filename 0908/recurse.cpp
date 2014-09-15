/*************************************************************************
	> File Name: recurse.cpp
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  9/ 8 23:14:23 2014
 ************************************************************************/

#include<iostream>
using namespace std;

int cannonball(int height)
{
	if (height == 0) 
		return 0;
	else 
		return (height*height + cannonball(height - 1));
}

string reverseString(string str)
{
	if (str.length() == 0)
		return "";
	else 
		return reverseString(str.substr(1)) + str[0];
}

string reverseStringIterative(string str)
{
	string result = "";
	for (int i = str.length() - 1; i >= 0; i--) {
		result += str[i];
	}
	return result;
}

bool isOffGrid(pointT pt, Grid<pixelStateT> &grid)
{
	return pt.row < 0 || pt.col < 0 || pt.row >= grid.numRows || pt.col >= numRows;
}

void fillRegion(pointT pt, Grid<pixelStateT> &screen)
{
	if (isOffGrid(pt, screen) || screen(pt.row, pt.col) == Black)
		return;

	screen(pt.row, pt.col) = Black;
	pointT east = {pt.row, pt.col + 1};
	fillRegion(east, screen);

	pointT west = {pt.row, pt.col - 1};
	fillRegion(west, screen);

	pointT north = {pt.row + 1, pt.col};
	fillRegion(north, screen);

	pointT sourth = {pt.row - 1, pt.col};
	fillRegion(sourth, screen);
}

void recursiveMnemonics(string prefix, string rest)
{
	if (rest.length() == 0) 
		cout << prefix << endl;
	else {
		string opitions = digitLetters(rest[0]);
		for (int i = 0; i < opitions.length(); i++) {
			recursiveMnemonics(prefix, rest.substr[1]);
		}
	}
}
