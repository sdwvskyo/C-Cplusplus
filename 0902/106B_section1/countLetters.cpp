/*************************************************************************
	> File Name: countLetters.cpp
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  9/ 3 10:43:43 2014
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

const int AlphabetSize = 26;

void countLetters(string filename)
{
	ifstream in;
	in.open(filename.c_str());
	if (in.fail())
		Error("Coundn't open");

	Vector<int> result;
	for (int i = 0; i < AlphabetSize; i++) {
		result.add(0);
	}
	string line;
	while (true) {
		getline(in, line);
		if (in.fail())
			break;
		line = converToLoweerCase(line);
		for (int j = 0; j < line.length(); j++) {
			int index = line[j] - 'a';
			if (index >= 0 && index <= AlphabetSize) {
				result[index]++;
			}
		}
	}
	for (int k = 0; k < AlphabetSize; k++) {
		char currLetter = 'a' + k;
		cout << currLetter << ":" << result[k] << endl;
	}
}
