/*************************************************************************
	> File Name: censorString.cpp
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 二  9/ 2 09:16:22 2014
 ************************************************************************/

/*
 * Problem 1: Removing all occurrences of a character
 * If we want to remove the occurrences of the letter one at a time, returning a completely new string at the end, we can write the following function:
*/


#include <iostream>
#include <string>
using namespace std;

string censorString1(string text, string remove)
{
	string result = "";
	for (int i = 0; i < text.length(); i++) {
		bool found = false;
		for (int j = 0; j < remove.length(); j++) {
			if (text[i] == remove[j]) {
				found = true;
				break;
			}
		}
		if (!found) {
			result += text[i];
		}
	}
	return result;
}

string censorString2(string text, string remove)
{
	int pos;

	for (int i = 0; i < remove.length(); i++) {
		while(true) {
			pos = text.find(remove[i]);
			if (pos == string::npos) {
				break;
			} else {
				text = text.substr(0, pos) + text.substr(pos + 1);
			}
		}
	}
	return text;
}

void censorString(string & text, string remove)
{
	for (int i = 0; i < remove.length(); i++) {
		int pos = 0;
		while ((pos = text.find(remove[i], pos)) != string::npos) {
			text.replace(pos, 1, "");
		}
	}
}

int main(void)
{
	string text, remove;
	cout << "Input a string" << endl;
	cin >> text;
	cout << "Input remove" << endl;
	cin >> remove;
	
	cout << censorString1(text, remove) << endl;
	cout << censorString2(text, remove) << endl;
	censorString(text, remove);
	cout << text << endl;
	return 0;
}
