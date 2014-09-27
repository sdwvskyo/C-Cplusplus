#ifndef WORDCOUNT_H_
#define WORDCOUNT_H_ 

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <stdexcept>
#include <vector>
#include <stdlib.h>
#include <sys/time.h>

using std::string;

double gettime();

class Words {
	public:
		Words() { };
		~Words() { };
		Words(const string &workfile, const string &excludefile);
		void loadExcludeFile(const string &filename);
		void loadWorkFile(const string &filename);
		void sortByFrequency();
		void printTopK(int k = 20) const;
		void printByWordOrder(int n = 20) const;
	private:
		std::set<string> exclude;
		std::map<string, int> wordMap;
		std::vector<std::pair<string, int> > wordVec;
};

#endif  /*WORDCOUNT_H_*/
