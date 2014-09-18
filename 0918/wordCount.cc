#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <assert.h>
#include <stdexcept>

using namespace std;

struct Word {
	string word_;
	int cnt_;
};

void deletePunct(string &s)
{
	for (size_t i = 0; i < s.size(); i++) {
		if (ispunct(s[i]))
			s.erase(i);
	}
}

int main(int argc, const char *argv[])
{
	assert(argc == 2);
	vector<Word> words;
	ifstream infile(argv[1]);
	if (!infile)
		throw runtime_error("open file fail");
	string s;
	while (infile >> s) {
		deletePunct(s);
		size_t i;
		for (i = 0; i != words.size(); i++) {
			if (words[i].word_ == s) {
				words[i].cnt_++;
				break;
			}
		}
		if (i == words.size()) {
			Word word;
			word.word_ = s;
			word.cnt_ = 1;
			words.push_back(word);
		}
	}
	for(vector<Word>::iterator it = words.begin(); it != words.end(); ++it){
		cout << it->word_ << " " << it->cnt_ << endl;	
	}
	return 0;
}
