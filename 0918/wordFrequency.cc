#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#define ERR_EXIT(m) \
	do { \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

using namespace std;

struct Word {
	string word_;
	int cnt_;
};

void readFile(const char *filename, vector<Word> &words);
void sortByFrequency(vector<Word> &words);
void printWords(const vector<Word> &words);
void erasePunct(string &s);
bool cmp(const Word &a, const Word &b);

int main(int argc, const char *argv[])
{
	if (argc != 2) 
		throw runtime_error("argument less");

	vector<Word> words;

	readFile(argv[1], words);

	sortByFrequency(words);

	printWords(words);
	return 0;
}

void readFile(const char *filename, vector<Word> &words)
{
	ifstream infile(filename);
	if (!infile)
		ERR_EXIT("ifstream");
	string s;
	while (infile >> s) {
		erasePunct(s);
		vector<Word>::iterator it;
		for(it = words.begin(); it != words.end(); ++it){
			if (it->word_ == s) {
				it->cnt_++;
				break;
			}
		}
		if (it == words.end()) {
			Word word;
			word.word_ = s;
			word.cnt_ = 1;
			words.push_back(word);
		}
	}
	infile.close();
}

void sortByFrequency(vector<Word> &words)
{
	sort(words.begin(), words.end(), cmp);
}

bool cmp(const Word &a, const Word &b)
{
	return a.cnt_ > b.cnt_;
}

void printWords(const vector<Word> &words)
{
	int cnt = 0;
	for(vector<Word>::const_iterator it = words.begin(); it != words.end(); ++it){
		cout << it->word_ << " " << it->cnt_ << endl;
		cnt++;
	}
	cout << "total: " << cnt << endl;
}

void erasePunct(string &s)
{
	string::iterator it = s.begin();
	while (it != s.end()) {
		if (ispunct(*it))
			it = s.erase(it);
		else 
			++it;
	}
}
