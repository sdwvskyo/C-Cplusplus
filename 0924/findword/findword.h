#ifndef FINDWORD_H_
#define FINDWORD_H_ 

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using std::string;
using std::map;
using std::set;
using std::vector;
using std::ifstream;

class Word {
	public:
		Word() {  }
		~Word() {  }
		Word(ifstream &infile);

		void loadFile(ifstream &infile);
		void findWord(const string &word);

	private:
		map<string, int> wordCnt;
		map<string, set<int> > wordLineNo;
		vector<string> lines;
};

#endif  /*FINDWORD_H_*/
