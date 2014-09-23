#ifndef SEARCH_H_
#define SEARCH_H_ 

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <sstream>
using std::string;
using std::vector;

class Search {
	public:
		Search();
		Search(const string &filename);
		~Search();
		void loadFile(const string &filename);
		void wordSearch(const string &line) const;
	private:
		vector<string> words_;
};

#endif  /*SEARCH_H_*/
