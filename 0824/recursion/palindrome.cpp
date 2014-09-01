/*************************************************************************
	> File Name: palindrome.cpp
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  8/24 10:40:25 2014
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
	if (s.length() <= 1)
		return true;
	else
		return s[0] == s[s.length() - 1] && 
			isPalindrome(s.substr(1, s.length() - 2));
}

int main(int argc, char *argv[])
{
	string str;
	while (1) {
		cin >> str;
		if (str[0] == '\0' || str[0] == '\n')
			break;
		if (isPalindrome(str))
			cout << str << " is palindrome." << endl;
		else 
			cout << str << " is not palindrome" << endl;
	}
	return 0;
}
