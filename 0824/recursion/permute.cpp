/*************************************************************************
	> File Name: permute.cpp
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  8/25 22:31:46 2014
 ************************************************************************/

#include<iostream>
using namespace std;

void recPermute(string soFar, string rest)
{
	if (rest == "") {
		cout << soFar << endl;
	} else {
		for (int i = 0; i < rest.length(); i++) {
			string next = soFar + rest[i];
			string remain = rest.substr(0, i) + rest.substr(i + 1);
			recPermute(next, remain);
		}
	}
}

void ListPermute(string s)
{
	recPermute("", s);
}


int main(void) {
	string s;
	cout << "Input a string:" << endl;
	cin >> s;
	ListPermute(s);
	return 0;
}
