/*************************************************************************
	> File Name: linklist.cpp
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  9/ 9 10:52:10 2014
 ************************************************************************/

#include<iostream>
using namespace std;

struct Cell {
	Cell *next;
	int value;
};

Cell * converToListIter(Vector<int> vector)
{
	Cell *head = new Cell;
	head->next = NULL;
	head->value = vector[0];

	Cell *tail = head;
	for (int i = 1; i < vector.size(); i++) {
		Cell *newCell = new Cell;
		newCell->value = vector[i];
		newCell->next = NULL;

		tail->next = newCell;
		tail = newCell;
	}
	return head;
}

Cell * converToListRecur(Vector<int> vector, int index)
{
	if (index >= vector.size())
		return NULL;
	else {
		Cell *newCell = new Cell;
		newCell->value = vector[index];
		newCell->next = converToListRecur(vector, index + 1)
	}
	return newCell;
}

Cell * converToListRecur(vector<int> vector)
{
	converToListRecur(vector, 0);
}

int sumListIter(Cell *list)
{
	int sum = 0;
	Cell *curr = list;
	while (curr) {
		sum += curr->value;
		curr = curr->next;
	}
	return sum;
}

int sumListRecur(Cell *list)
{
	if (list == NULL) 
		return 0;
	else 
		return list->value + sumListRecur(list->next);
}

void append(Cell * & first, Cell *second)
{
	if (first == NULL) 
		first = second;
	else 
		append(first->next, second);
}
