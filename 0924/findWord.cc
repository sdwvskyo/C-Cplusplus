#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>
#include <fstream>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct Attr {
	int count_;
	set<int> lineNo_;
	set<string> lines_;

	void printAttr() 
	{
		cout << "count: " << count_ << endl;
		cout << "lineNo.: ";
		for (int i : lineNo_)
			cout  << i << " ";
		cout << endl;
		cout << "lines: " << endl;
		for (const string &s : lines_)
			cout << s << endl;
	}
};

void loadFile(const string &filename, map<string, Attr> &words);
void findWord(map<string, Attr> &words, const string &word);
void erasePunct(string &word);

int main(int argc, const char *argv[])
{
	map<string, Attr> words;
	loadFile(argv[1], words);
	string word;
	cout << "Which word you want to find: " << endl;
	while(cin >> word) {
		findWord(words, word);
	}
	return 0;
}

void erasePunct(string &word)
{
	string::iterator it = word.begin();
	while (it != word.end()) {
		if (ispunct(*it))
			it = word.erase(it);
		else
			++it;
	}
}

void loadFile(const string &filename, map<string, Attr> &words)
{
	int cnt = 0;
	ifstream infile(filename);
	if (!infile)
		throw runtime_error("open file");
	string line;
	string word;
	while(getline(infile, line)) {
		cnt++;
		istringstream in(line);
		while (in >> word) {
			erasePunct(word);
			words[word].count_++;
			words[word].lineNo_.insert(cnt);
			words[word].lines_.insert(line);
		}
	}
	infile.close();
}

void findWord(map<string, Attr> &words, const string &word)
{
	if (words.find(word) != words.end()) {
		cout << word << endl;
		words[word].printAttr();
	}
	else 
		cout << "no this word!" << endl;
}
