#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <sys/time.h>
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

double readFile(const char *filename1, const char *filename2, vector<Word> &words);
double sortByFrequency(vector<Word> &words);
double printWords(const vector<Word> &words);
void erasePunct(string &s);
bool cmp(const Word &a, const Word &b);
bool isInBlackFile(const vector<string> &vec, const string &s);
void addWord(vector<Word> &words, const string &s);
double getTime();
bool binarySearch(const vector<string> &vec, const string &s);

int main(int argc, const char *argv[])
{
	if (argc != 3) 
		throw runtime_error("argument less");

	vector<Word> words;

	double time1 = readFile(argv[1], argv[2], words);

	double time2 = sortByFrequency(words);

	double time3 = printWords(words);

	cout << "read file cost: " << time1 << "sec" << endl;
	cout << "sort cost: " << time2 << "sec" << endl;
	cout << "print cost: " << time3 << "sec" << endl;
	return 0;
}

double readFile(const char *filename1, const char *filename2, vector<Word> &words)
{
	double timeBeg = getTime();
	ifstream infile(filename1);
	ifstream black(filename2);
	if (!infile || !black)
		ERR_EXIT("ifstream");

	vector<string> blackWords;
	string s;
	while (black >> s) {
		blackWords.push_back(s);
	}

	while (infile >> s) {
		erasePunct(s);
		if (!isInBlackFile(blackWords, s))
			addWord(words, s);
	}
	infile.close();
	double timeEnd = getTime();
	double time = timeEnd - timeBeg;
	return time;
}

bool isInBlackFile(const vector<string> &vec, const string &s)
{
	return binarySearch(vec, s);
}

bool binarySearch(const vector<string> &vec, const string &s)
{
	int begin = 0;
	int end = vec.size() - 1;
	int mid;
	while (begin <= end) {
		mid = (begin + end) / 2;
		if (vec[mid] == s)
			return true;
		else if (vec[mid] < s)
			begin = mid + 1;
		else 
			end = mid - 1;
	}
	return false;
}


void addWord(vector<Word> &words, const string &s)
{
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

double sortByFrequency(vector<Word> &words)
{
	double timeBeg = getTime();
	sort(words.begin(), words.end(), cmp);
	double timeEnd = getTime();
	double time = timeEnd - timeBeg;
	return time;
}

bool cmp(const Word &a, const Word &b)
{
	return a.cnt_ > b.cnt_;
}

double printWords(const vector<Word> &words)
{
	double timeBeg = getTime();
	int cnt = 0;
	for(vector<Word>::const_iterator it = words.begin(); it != words.end(); ++it){
		cout << it->word_ << " " << it->cnt_ << endl;
		cnt++;
	}
	cout << "total: " << cnt << endl;
	double timeEnd = getTime();
	double time = timeEnd - timeBeg;
	return time;
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


double getTime()
{
	timeval tm;
	memset(&tm, 0, sizeof tm);
	gettimeofday(&tm, NULL);
	double result = 0.0;
	result += (tm.tv_sec + tm.tv_usec / (double) 1000000);
	return result;
}
