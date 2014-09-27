#include "findword.h"

using namespace std;

Word::Word(ifstream &infile)
{
	loadFile(infile);
}

static void erasePunct(string &s)
{
	string::iterator it = s.begin();
	while (it != s.end()) {
		if (ispunct(*it))
			it = s.erase(it);
		else
			++it;
	}
}

void Word::loadFile(ifstream &infile)
{
	lines.push_back(" ");
	int cnt = 0;
	string line;
	while (getline(infile, line)) {
		cnt++;
		lines.push_back(line);
		istringstream stream(line);
		string word;
		while (stream >> word) {
			erasePunct(word);
			++wordCnt[word];
			wordLineNo[word].insert(cnt);
		}
	}
}

void Word::findWord(const string &word)
{
	if (wordCnt.find(word) != wordCnt.end()) {
		cout << "Count: " << wordCnt[word] << endl;
		cout << "LineNo.: " ;
		for (int i : wordLineNo[word])
			cout << i << " ";
		cout << endl;
		for (int i : wordLineNo[word])
			cout << lines[i] << endl;
	} else {
		cout << "No this word" << endl;
	}
}
