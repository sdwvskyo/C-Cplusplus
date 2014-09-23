#include "Search.h"

using namespace std;

Search::Search()
{
	
}

Search::Search(const string &filename)
{
	loadFile(filename);
}

Search::~Search()
{

}

void Search::loadFile(const string &filename)
{
	ifstream infile(filename);
	if (!infile)
		throw runtime_error("ifstream");
	string s;
	while (infile >> s) {
		words_.push_back(s);
	}
	infile.close();
}

void Search::wordSearch(const string &line) const
{
	istringstream inLine(line);
	string word;
	while (inLine >> word) {
		for(size_t ix = 0; ix < words_.size(); ++ix) {
			if (words_[ix].find(word) != string::npos) 
				cout << words_[ix] << endl;
		}
	}
}
