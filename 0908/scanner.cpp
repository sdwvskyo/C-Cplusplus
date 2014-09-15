/*************************************************************************
	> File Name: scanner.cpp
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  9/ 8 10:21:19 2014
 ************************************************************************/

#include<iostream>
#include <scanner>
using namespace std;

void countTokens()
{
	Scanner scanner;
	cout << "Input a setence:";
	scanner.setInput(GetLine());
	int count = 0;
	while (scanner.hasMoreTikens()) {
		scanner.netToken();
		count++;
	}
	cout << "you entered" << cout << "token" << endl;
}

int main(void)
{
	countTokens();
	return 0;
}
