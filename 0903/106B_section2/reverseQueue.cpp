/*************************************************************************
	> File Name: reverseQueue.cpp
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  9/ 3 16:39:01 2014
 ************************************************************************/

#include<iostream>
using namespace std;

void reverseQueue(Queue<int> & q)
{
	Stack<int> stack;
	while (!q.isEmpty()) {
		stack.push(q.dequeue());
	}
	while (!stack.isEmpty()) {
		q.enqueue(stack.pop());
	}
}
