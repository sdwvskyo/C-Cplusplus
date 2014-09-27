#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct Score {
	int id_;
	string name_;
	int score_;
};

void loadFile(ifstream &infile, vector<Score> &scores);
bool cmp(const Score &s1, const Score &s2);
bool isPass(const Score &s);

int main(int argc, const char *argv[])
{
	if (argc < 2)
		throw runtime_error("argument less");

	ifstream infile(argv[1]);	
	if (!infile)
		throw runtime_error("open file");

	vector<Score> scores;
	loadFile(infile, scores);
	int cnt = count_if(scores.begin(), scores.end(), isPass);
	cout << cnt << " student's score >= 60 " << endl;

	vector<Score>::iterator it = 
		max_element(scores.begin(), scores.end(), cmp);
	cout << "max score is: " << it->id_ << " " << it->name_ 
		 << ": " << it->score_ << endl;

	infile.close();
	return 0;
}

void loadFile(ifstream &infile, vector<Score> &scores)
{
	string line;
	while (getline(infile, line)) {
		istringstream stream(line);
		if (!stream) 
			throw runtime_error("istringstream");
		Score score;
		memset(&score, 0, sizeof score);
		while (stream >> score.id_ >> score.name_ >> score.score_)
			scores.push_back(score);
	}
}

bool isPass(const Score &s)
{
	return s.score_ >= 60;
}

bool cmp(const Score &s1, const Score &s2)
{
	return s1.score_ < s2.score_;
}
