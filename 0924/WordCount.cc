#include "WordCount.h"

using namespace std;

static void erasePunct(string &word)
{
	string::iterator it = word.begin();
	while (it != word.end()) {
		if (ispunct(*it))
			it = word.erase(it);
		else 
			++it;
	}
}

Words::Words(const string &workfile, const string &excludefile)
{
	loadExcludeFile(excludefile);
	loadWorkFile(workfile);
}

void Words::loadExcludeFile(const string &filename)
{
	ifstream infile(filename);
	if (!infile)
		throw runtime_error("open file");

	string word;
	while (infile >> word) {
		exclude.insert(word);
	}
	infile.close();
}

void Words::loadWorkFile(const string &filename)
{
	ifstream infile(filename);
	string word;
	while (infile >> word) {
		erasePunct(word);
		if (word == "")
			continue;
		if (exclude.find(word) == exclude.end())
			++wordMap[word];
	}
	infile.close();
}

static bool cmp(const pair<string, int> &p1, const pair<string, int> &p2)
{
	return p1.second > p2.second;
}

void Words::sortByFrequency()
{
	for(const pair<string, int> &p : wordMap) 
		wordVec.push_back(p);
	sort(wordVec.begin(), wordVec.end(), cmp);
}

void Words::printTopK(int k) const
{
	for (int i = 0; i < k; ++i)
		cout << wordVec[i].first << ": " << wordVec[i].second << endl;
}

void Words::printByWordOrder(int n) const
{
	int cnt = 0;
	map<string, int>::const_iterator it = wordMap.begin();
	while (cnt != n && it != wordMap.end()) {
		cout << it->first << ": " << it->second << endl;
		++it;
		++cnt;
	}
}

double gettime()
{
	timeval tm;
	memset(&tm, 0, sizeof tm);
	gettimeofday(&tm, NULL);
	double result = 0.0;
	result += (tm.tv_sec + tm.tv_usec / (double)1000000 );
	return result;
}
